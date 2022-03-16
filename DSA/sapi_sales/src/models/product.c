//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "product.h"
#include "errors.h"
#include "useful.h"

//Fuggvenyek definicioja

char* getProductType(enum ProductType type){
    switch(type){
        case GROCERY:
            return "Grocery";
        case FRUIT:
            return "Fruit";
        case  SCHOOL:
            return "School";
        case OBJECT:
            return "Object";
        default:
            return "Undefined";
    }
}
void createProduct(Product ** product) {
    *product = (Product *) malloc(sizeof(Product));
    if (!(*product)) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*product)->name = (char *) (malloc(20 * sizeof(char)));
    if (!(*product)->name) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*product)-> id = ++numberOfProducts;
}

void setProductData(Product *product, char *name, enum ProductType type, unsigned int amount, int price){
    if(!product){
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    strcpy(product -> name, name);
    product -> type = type;
    product -> amount = amount;
    product -> price = price;
    product -> creationDate = time(NULL);
}

void printProduct(Product *product, char *destination ){
    if(!product){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    freopen(destination, "w", stdout);
    printf("\n\t%s details:"
           "\n\t\t - ID: %i"
           "\n\t\t - TYPE: %s"
           "\n\t\t - AMOUNT: %u"
           "\n\t\t - CREATION: %ld\n",
           product->name,
           product->id,
           getProductType(product->type),
           product->amount,
           product->creationDate);
    freopen("CON", "w", stdout);
}

void deleteProduct(Product **product) {
    if(product != NULL) {
        free(*product);
        *product = NULL;
    }
}
#ifndef BANKLINKEDLIST_H
#define BANKLINKEDLIST_H
/*----------------------------------Includes---------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------Data Types--------------------------------*/
typedef struct customer{
    char name[50];
    float cash;
    char type[7];
    int id;
    struct customer *next;
}customer_t;

/*----------------------------------Functions----------------------------------*/

/**
 * @brief Ahmed Adel Wafdy
 * 
 * @param head 
 * @param id 
 * @return int number to validate the node of linked list 
 * and to validate the existance of the customer.
 */
int check_id(customer_t *head,int id);
/**
 * @brief Create a customer object
 * 
 * @param head_ptr 
 * @return void data
 * Create a new node in linked list with new data  
 */
void create_customer(customer_t **head_ptr);
/**
 * @brief Ahmed Adel Wafdy
 * 
 * @param head 
 * @param id 
 * @return void data 
 * Edit customer data 
 */
void edit_customer(customer_t *head,int id);
/**
 * @brief Ahmed Adel Wafdy
 * 
 * @param head_ptr 
 * @param head 
 * @param id 
 * @return void data 
 * delete customer data from data base
 */
void delete_customer(customer_t **head_ptr,customer_t *head,int id);
/**
 * @brief Ahmed Adel Wafdy
 * 
 * @param head 
 * @param id 
 * @return void data 
 * Print full customer data : name, id, cash..and any other data
 */
void print_customer_data(customer_t *head,int id);
/**
 * @brief Ahmed Adel Wafdy
 * 
 * @param head 
 * @param from_id 
 * @param to_id 
 * @param money 
 * @return void 
 * Transfer money from customer to another 
 */
void Transfer_money(customer_t *head,int from_id,int to_id,double money);
#endif
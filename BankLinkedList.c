#include "BankLinkedList.h"
/* Counter of the number of customers */
int counter;
int check_id(customer_t *head,int id){
    int check = -1; 
    /* validate head */
    if(NULL==head){
        check=-1;
    }
    /* While loop to check head's id */
    while(NULL!=head){
        if(id==head->id){
        check=2;
        break;
        }
        head=head->next;
    }
    return check;
}

void create_customer(customer_t **head_ptr){
    /* Dynamic memory alloctaion to the size of the struct */
    customer_t *new_customer;
    new_customer = (customer_t *)malloc(sizeof(customer_t)); 
    /* Get an input (name ,cash ,debit or credit,id) and clear the buffer with fflush */
    printf("Please enter the name of the customer number %i:",counter+1);
    fgets((new_customer->name),50,stdin);
    printf("\n\n");
    label: printf("Please enter the cash of the customer number %i:",counter+1);
    scanf("%1f",&(new_customer->cash));
    if(new_customer->cash<0){
        printf(" Please,Enter a cash which is poitive number greater than or equal zero \n");
        goto label;
    }
    printf("\n\n");
    printf(" Please enter the type of the customer number %i (debit or credit) :",counter+1);
    fgets((new_customer->type),7,stdin);
    printf("\n\n");
    printf("Please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(new_customer->id));
    /* change the link of the node to the next node */
    new_customer->next = *head_ptr;
    *head_ptr = new_customer;
    /* upgrade counter */
    counter++;
}

void edit_customer(customer_t *head,int id){
    /* validate head */
        if(NULL==head){
            printf(" The linked list is empty \n");
            return ;
        }

    /* Get the new data */
    while(NULL!=head){
        if(head->id==id){
            printf("please enter the new name :");
            fflush(stdin);
            gets(head->name);
            printf("\n\n");
            printf("please enter the new cash :");
            scanf("%1f",&(head->cash));
            printf("\n\n");
            printf("please enter the new type (debit or credit)  :");
            fflush(stdin);
            gets(head->type);
            printf("\n\n");
            printf("please enter the new id :");
            scanf("%i",&(head->id));                        
            break;
        }
        head=head->next;
    }
    printf("\n\n");
}

void delete_customer(customer_t **head_ptr,customer_t *head,int id){
    int i=0;
    int j;
    customer_t *temp;
    customer_t *temp2=head;
    if(head==NULL)
    {
        printf("the linked list is empty \n");
        return ;
    }
    if(head->next==NULL)
    {
        free(*head_ptr);
        *head_ptr=NULL ;
        counter--;
        return ;
    }
    while(head!=NULL)
    {
        if(head->id==id)
        {
            break;
        }
        head=head->next;
        i++;
    }
    if(i==0)
    {
        *head_ptr=(*head_ptr)->next;
        free(temp2);
        counter--;
        return;
    }
    for(j=0;j<i-1;j++)
    {
        temp2=temp2->next;
    }
    printf("i=%i",i);
    printf("j=%i",j);
    temp=temp2->next;
    temp2->next=temp->next;
    free(temp);
    counter--;
}

void print_customer_data(customer_t *head,int id){
    /* check if linked list is empty */
    if (NULL==head){
        printf("The linked list is empty \n");
        return;
    }
    /* get the id and print the data of the customer */    
    while(NULL!=head){
        if(id==head->id){
            printf("The name of the customer number %i is: %s\n",counter+1,(head->name));
            printf("The cash of the customer number %i is: %0.2f\n",counter+1,(head->cash));
            printf("The type of the customer number %i is: %s\n",counter+1,(head->type));
            printf("The id of the customer number %i is: %i\n",counter+1,(head->id));
            printf("\n\n");
            break;
        }
        head=head->next;
    }

}

void Transfer_money(customer_t *head,int from_id,int to_id,double money){
    customer_t *temp = head;
    /* check if linked list is empty */
    if (NULL==head){
        printf("The linked list is empty \n");
        return;
    }    
    /* check if there are one element */
    if(NULL==head->next){
        printf("The linked list is containaing one element you can transfer money at least between 2 elements \n");
        return;
    }
    /* get the client by id */
    while(NULL!=head){
        if(from_id==head->id){
    /* validate the transfer money amount*/        
            if(head->cash-money<0){
                printf(" The transfered money is more than client money\n");
                return ;
            }
            head->cash = head->cash - money;
            break;
        }
        head=head->next;

    }
    while(NULL!=temp){
        if(to_id==temp->id){
            temp->cash = temp->cash + money;
            break;
        }
        temp=temp->next;
    }

}

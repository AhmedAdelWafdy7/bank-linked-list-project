#include "BankLinkedList.h"
int main(){
    char choice;
    int id_check,to_id,from_id,check1,check2;
    double transfer_money;
    customer_t *head='\0';
    while(1){
        printf("please select one of the following options : \n\n1- Create a new customer (press1 to select this option)\n2- Edit customer data (press 2 to select this option)\n3- Delete customer data (press 3 to select this option)\n4- Print customer data (press4 to select this option)\n5- Transfer cash form client to another (press 5 to select this option)\n6- Exit (press 6 to select this option)\n\nPlease enter your choice : ");
        fflush(stdin);
        scanf("%c",&choice);
        printf("\n\n");
        switch(choice){
            case '1':
                create_customer(&head);
                break;
            case '2':
                edit: printf("Please enter the id of the customer you want to edit :");
                      scanf("%i",&id_check);
                      check1 = check_id(head,id_check);
                      if(-1 == check1){
                        printf("Please Enter valid id \n");
                        goto edit;
                      }
                      edit_customer(head,id_check);
                      break;
            case '3':
                delete: printf("Please enter the id of the customer you want to delete :");
                      scanf("%i",&id_check);
                      check1 = check_id(head,id_check);
                      if(-1 == check1){
                        printf("Please Enter valid id \n");
                        goto delete;
                      }
                      delete_customer(&head,head,id_check);
                      break;                
            case '4':
                print: printf("Please enter the id of the customer you want to print his data :");
                      scanf("%i",&id_check);
                      check1 = check_id(head,id_check);
                      if(-1 == check1){
                        printf("Please Enter valid id \n");
                        goto print;
                      }
                      print_customer_data(head,id_check);
                      break;
            case '5':
                first_id: printf("Please enter the id of the customer you want to transfer money from his cash :");
                      scanf("%i",&id_check);
                      check1 = check_id(head,id_check);
                      if(-1 == check1){
                        printf("Please Enter valid id \n");
                        goto first_id;
                      }
                second_id: printf("Please enter the id of the customer you want to transfer money to his cash :");
                      scanf("%i",&id_check);
                      check1 = check_id(head,id_check);
                      if(-1 == check1){
                        printf("Please Enter valid id \n");
                        goto second_id;
                      }
                money: printf("Please enter the amount of money you want to transfer :");
                      scanf("%1f",&transfer_money);
                      if(transfer_money<=0){
                        printf("Please Enter a valid amount of money \n");
                        goto money;
                      }                      
                Transfer_money(head,from_id,to_id,transfer_money);
                break;
            case '6':
                exit(0);
            default:
                printf("Wrong choice\n");    

        }
    }
    return 0;
}
#include<food.h>

struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};

   ///Global Type

typedef struct Node node ;

node *head, *list;

int main(){

	loadingbar();
	cls();
	pwelcome();
	Sleep(300);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(1,"Burger  ",23,120.23);
	insertend(2,"Pizza  ",13,100.67);
	insertend(3,"Chocolate Cake",8,720.83);
	insertend(4,"Coffee  ",46,70.23);
	insertend(5,"Ice-Cream  ",46,70.23);
	insertend(6,"Sandwich  ",34,60.23);
	insertend(7,"Grill  ",7,520.29);
	insertend(8,"Garlic Bread",121,35.13);
	insertend(9,"Cold Drinks ",73,20.13);

	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			printf("=> 0. Main Menu ");
			foodlist();


		}

		else if( main_menu_choice == 2){

			int admin_panel_choice;
			adminpanelchoice:


			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");


			fflush(stdin);  scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==123321){

				node *temp;

				temp = list;

				adminchoice:

				cls();  br(5); pre(4); echo("You are on Admin Panel\n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Pay \n\n");Sleep(250);pre(4);
				printf(" 3. Add Food \n\n");Sleep(250);pre(4);
				printf(" 4. Delete Food \n\n");Sleep(250);pre(4);
				printf(" 5. Instant Food List \n\n");Sleep(250);pre(4);
				printf(" 6. Item Counter \n\n");Sleep(250);pre(4);
				printf(" 7. Backup System\n\n");Sleep(250);pre(4);
				printf(" 8. Instant Order Preview\n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu \n\n");
				printf("Enter Your From 1-0: ");
				Sleep(250);

				int adminchoice;

				fflush(stdin);   scanf("%d",&adminchoice);

				if(adminchoice==1){

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);

					Sleep(2000);

					goto adminchoice;
				}
				else if(adminchoice==2){

					if(c!=0){

						cls();  br(3); pre(4);

						printf(" ____________________________\n");pre(4);
						printf("|   Card NO.   |   Money $   |\n");pre(4);
						printf("------------------------------\n");pre(4);

						for(int z=1; z<=c;z++){

							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);pre(4);
							printf("------------------------------\n");pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					printf("No Card History\n");}
					Sleep(1500);
					goto adminchoice;
				}

				else if(adminchoice==3){

					foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);      printf(" Enter Food Name :  ");

					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);

					br(2);pre(4);
					printf(" Enter Food Quantity :  ");

					scanf("%d",&fquantity); fflush(stdin);

                        foodserial:
					br(2);pre(4);  printf(" Enter Food Serial :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){
                       cls(); br(5);pre(3);  printf(" Food Serial Already Exist, Please Re-Enter  "); Sleep(2000);
                       goto foodserial;
                      }

                    fprice:
                      fflush(stdin);

					br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);

					scanf("%f",&fprice);



					br(2);pre(4);  printf("Submitting your data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}


					insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Adding Food  Successful....\n");

					Sleep(2000);

					goto adminchoice;

				}
				else if(adminchoice==4){

					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Food To Delete : ");

					int fdelete;
					fdelete:

					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}


					goto adminchoice;
				}

				else if(adminchoice==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);



					fflush(stdin);   scanf("%d",&any);

					goto adminchoice;

				}

				else if(adminchoice==6){

					citem = countitem();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						printf("Item Counting ");
						printf(" %d ",cs);
						Sleep(150);
						cls();
					}
					cls();
					middle1();pre(4);
					printf("Total Food Item is --> %d  \n",citem); Sleep(2000);
					goto adminchoice;

				}

                        ///Backup System
				else if(adminchoice==7){


					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); printf("Error!"); Sleep(500);
						goto adminchoice;
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Successful..."); Sleep(1500);



					fclose(fptr);
					goto adminchoice;
				}
				else if(adminchoice==8){

					cls();br(2);pre(2);
					ccolor(26);
					printf("\n\t\t"); ccolor(240);
					printf("______________________________________________________ "); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("|  Order No.  |   Food Name   |  Quantity |  In Stock |"); ccolor(26);
					printf("\n\t\t");  ccolor(240);
					printf("------------------------------------------------------"); ccolor(26);
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					goto adminchoice;



				}
				else if(adminchoice==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoice;
				}

			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Thank You For Using Our System \n\n\n\n\n\n\n");
			Sleep(1000);

			exit(1);

		}

	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3);fflush(stdin);
	printf("Place Your Order: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choice From List: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		printf("Enter Food Quantity : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity); cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);

			goto foodlist;
		}

		middle1();pre(4);  printf("Choice food %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		printf("2. Food List \n\n");
		printf("Press 1 to confirm and 2 to back to list :");

		int confirm;
		confirm:

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(4);
			printf(" 1. Cash ");
			br(2);pre(4);
            printf(" 2. Credit\n");
            printf("Select Method Of payment 1-2: ");

			int payment;
			payment:


			fflush(stdin);  scanf("%d",&payment);

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  printf("===>THANK YOU<===");
				br(2);pre(4);  printf("Food Ordered Successfully ...");
				br(2);pre(4);  printf("1. Wanna Buy Another Delicious ? ");
				br(2);pre(4);  printf("2. Main Menu \n");
				br(2);pre(4);   printf("Select: ");

				int ps_menu;
				psmenu:

				fflush(stdin);  scanf("%d",&ps_menu);

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){

				int card_number[100];

				c++;

				cls();middle1();pre(4); printf("Enter Your Card No : ");

				fflush(stdin);   scanf("%d",&card_number[c]);



				cardno[c] = card_number[c];

				int pin;

				br(2);pre(2);  printf("Enter Your Card Pin [we never save your pin]  : ");

				fflush(stdin);     scanf("%d",&pin);

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				br(2);pre(4);  printf("Payment Success...");
				br(2);pre(4);    printf("1. Wanna Buy Another Delicious ? ");
				br(2);pre(4);    printf("2. Main Menu \n");
				br(2);pre(4);   printf("select: ");

				int ps_menu2;
				psmenu2:

				scanf("%d",&ps_menu2);

				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu2;}

			}

			else{

				br(2);pre(4);   printf("Enter Choice from List : ");

				goto payment;


			}


		}    ///END Confirm Y/y



		else if(confirm == 2){

			goto foodlist;

		}

		else{
			br(2);pre(4);    printf("Enter a Choice from List : ");

			goto confirm;


		}  ///end confirm;


	}  ///end get food choice if line


	else{

		br(2);pre(4);  echo("Please Select a Choice From List "); br(2); Sleep(300);

		goto foodlist;

	}  ///end get food choice
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bookInfo 
{
int bookId;
char bookName[30];
char authorName[30];
char category[30];
char categoryName[50];
double price;
double rating;
} BookInfo;

void storeBookInfo(BookInfo*, int);
void displayBookInfo(BookInfo*, int);
int searchBookInfo(BookInfo* , int );
void UpdateBookInfo(BookInfo*, int);
void deleteBookInfo(BookInfo* , int *);
void sortingBookInfo(BookInfo* ,int);


int main() 
{
    int choice,size=5;
    BookInfo book[size];
    do {
        printf("\n1.Store_book \n2.Display_book \n3.Search_book \n4.Delete_book \n5.Update_book \n6.Sorting_book");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                storeBookInfo(book, size);
                break;
            case 2:
                displayBookInfo(book, size);
                break;
            case 3:
                searchBookInfo(book, size);
                break;
             case 4:
                deleteBookInfo(book,&size);
                break;
             case 5:
                UpdateBookInfo(book, size);
                break;
             case 6:
     			sortingBookInfo(book, size);
                break;
            default:
                printf("\n Invalid Choice........");
        }
        printf("\n Do you want to continue? \n1.Yes \n2.No \nEnter any number to exit");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("\n Program exit successfully.....");

    return 0;
}

void storeBookInfo(BookInfo* ptr, int size) 
{
    printf("\n StoreBookInfo Function Called.");
    printf("\n-----------------------------------------");
    for (int i = 0; i < size; i++) 
	{
        printf("\nEnter the book_Id:");
        scanf("%d", &ptr[i].bookId);
        printf("\nEnter the book_Name:");
        scanf("%s", ptr[i].bookName);
        printf("\nEnter the book_Author_Name:");
        scanf("%s", ptr[i].authorName);
        printf("\nEnter the book_category_Name:");
        scanf("%s", ptr[i].categoryName);
        printf("\nEnter the book_Price:");
        scanf("%lf", &ptr[i].price);
        printf("\nEnter the book_Rating:");
        scanf("%lf", &ptr[i].rating);
    }
}

void displayBookInfo(BookInfo* ptr, int size) 
{
    printf("\n DisplayBookInfo Function Called.\n");
    printf("+-------------+-------------------------+-----------------+----------------------+---------------+---------------+\n");
    printf("| Book Id     |        Book Name        |   Author Name   |       Category       |     Price     |     Rating    |\n");
    printf("+-------------+-------------------------+-----------------+----------------------+---------------+---------------+\n");
    
    for (int i = 0; i < size; i++) 
    {
        printf("| %4d | %-26s | %-15s | %-20s | $%-12.2lf | %-13.2lf |\n",
               ptr[i].bookId, ptr[i].bookName, ptr[i].authorName, ptr[i].categoryName, ptr[i].price, ptr[i].rating);
    }
    
    printf("+--------------+------------------------+------------------+----------------------+---------------+--------------+\n");
}

int searchBookInfo(BookInfo *ptr, int size) {
    printf("\n SearchBookInfo Function Called.");
    printf("\n---------------------------------------");
    char ele[30];
    int choice;
    printf("\n1.bookId \n2.bookName");
    scanf("%d", &choice);
    int i;
    switch (choice) {
        case 1:
            printf("\nEnter the book Id you want to search: ");
            scanf("%d", &choice);
            for (i = 0; i < size; i++) {
                if (choice == ptr[i].bookId) {
                    printf("\nBookInfo is found at index %d:", i);
                    printf("\n book_Id: %d", ptr[i].bookId);
                    printf("\n book_Name: %s", ptr[i].bookName);
                    printf("\n book_author_Name: %s", ptr[i].authorName);
                    printf("\n book_category_Name: %s", ptr[i].categoryName);
                    printf("\n book_price: %lf", ptr[i].price);
                    printf("\n book_rating: %lf", ptr[i].rating);
                    return i;
                }
            }
            printf("\n Book not found....");
            break;
        case 2:
            printf("\nEnter the book name you want to search: ");
            scanf("%s", ele);
            for (i = 0; i < size; i++) {
                if (strcasecmp(ele, ptr[i].bookName) == 0) {
                    printf("\nBookInfo is found at index %d:", i);
                    printf("\n book_Id: %d", ptr[i].bookId);
                    printf("\n book_Name: %s", ptr[i].bookName);
                    printf("\n book_author_Name: %s", ptr[i].authorName);
                    printf("\n book_category_Name: %s", ptr[i].categoryName);
                    printf("\n book_price: %lf", ptr[i].price);
                    printf("\n book_rating: %lf", ptr[i].rating);
                    return i;
                }
            }
            printf("\nBook not found....");
            break;
        default:
            printf("\nInvalid choice....");
            break;
    }

    return -1;
}
    
    
void UpdateBookInfo(BookInfo* ptr, int size)
{
    printf("\n UpdateBookInfo Function Called.");
    printf("\n-------------------------------------------");
    
    int choice;
    printf("\n1.Price \n2.Rating");
    scanf("%d", &choice);
	int index= searchBookInfo(ptr ,size);
    switch (choice) 
	{
		case 1:
			printf("\n Enter new price of  book : ");
			scanf("%lf",&ptr[index].price);
			break;
			
		case 2:
			printf("\n Enter new rating of  book : ");
			scanf("%lf",&ptr[index].rating);
			break;
        
		default:
		printf("\nInvalid choice:");	
	}
			
}
void deleteBookInfo(BookInfo* ptr, int *size)
{
	printf("\n DeleteBookInfo Function Called.");
	printf("\n-------------------------------------------");
	char bookName[20];
	printf("\nEnter the book name you want to delete:");
	scanf("%s",&bookName);
	int index= searchBookInfo(ptr ,*size);
	if(index!=-1)
	{
		for(int i=index;i<*size;i++)
		{
			ptr[i]=ptr[i+1];
		}
	}
	(*size)--;
	
}

void sortingBookInfo(BookInfo* ptr, int size)
{
	printf("\n SortedBookInfo Function Called.");
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(ptr[j].rating>ptr[i].rating)
			{
			BookInfo temp =ptr[j];
			ptr[j]=ptr[i];
			ptr[i]= temp;
			}
		}
	}
	
	printf("\nSorted Book");
	displayBookInfo(ptr, size);
		
}


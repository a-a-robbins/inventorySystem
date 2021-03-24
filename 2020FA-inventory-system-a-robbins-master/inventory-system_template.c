#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct inventory_item
{
  char name[40]; 
  int onHand;
  double price; 
  int id; 
  char lastOrder[11];
};
typedef struct inventory_item item; 

int readFile(char filename[], struct inventory_item inventory_list[]);
int getTotalItems(struct inventory_item inventory_list[], int count);
double getTotalVal(struct inventory_item inventory_list[], int count);
void printItem(struct inventory_item inventory_list[], int count);


int main(int argc, char *argv[])
{
    item list[500]; 
    char file[20]; 
    int numItems;
    int totalItems;
    double totalVal; 
    char *item[500] = {NULL};

    printf("Enter file name: "); 
    scanf("%s", file); 

    numItems = readFile(file, list);
    totalItems = getTotalItems(list, numItems); 
    totalVal = getTotalVal(list, numItems);  

      printf("Total inventory value: $%0.2f\n", totalVal); 
      printf("Total inventory quantity: %d\n", totalItems);
      printf("Items that need to be ordered:\n");
      printItem(list, numItems);
   

    

	return 0;
}

int readFile(char filename[], struct inventory_item inventory_list[])
{
  
      FILE *ifp = NULL; 
      ifp = fopen(filename, "r");
      int numItems; 
	
	if(ifp == NULL)
      {
        printf("Sorry, the file did not open properly. Exiting\n"); 
        exit(1);
      }

      fscanf(ifp, "%d", &numItems); 

      for(int i = 0; i < numItems; i++)
      {
            
        fscanf(ifp, "%s", inventory_list[i].name);
        fscanf(ifp, "%d", &inventory_list[i].onHand);
        fscanf(ifp, "%lf", &inventory_list[i].price);
        fscanf(ifp, "%d", &inventory_list[i].id);
        fscanf(ifp, "%s", inventory_list[i].lastOrder);

      }
	
	fclose(ifp);
	
  return numItems; 
    
}

int getTotalItems(struct inventory_item inventory_list[], int count)
{
   int sum =0; 

    for(int i = 0; i < count; i++)
    {
        sum = sum + inventory_list[i].onHand;
    }

    return sum; 
}

double getTotalVal(struct inventory_item inventory_list[], int count)
{
    double sum = 0; 

    for(int i = 0; i < count; i++)
    {
      sum += inventory_list[i].onHand * inventory_list[i].price;
    }

    return sum;
}

void printItem(struct inventory_item inventory_list[], int count)
{
    for(int i = 0; i < count; i++)
    {
      if(inventory_list[i].onHand < 10)
      {
        printf("  %-s\n", inventory_list[i].name);

      }
    }
 
}

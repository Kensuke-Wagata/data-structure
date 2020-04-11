#include <stdio.h>
#include <stdlib.h>

typedef struct  _list{
    int data;
    struct _list *next;
} list;


list* create_matrix(int M) {
    int i;
    list *matrix = (list *)malloc(sizeof(list) * M);
    for(i = 0; i < M; i++){
      matrix[i].next = NULL;
      matrix[i].data = 0;
    }
    return matrix;
}

void AdjacencyListTableMake(int line, int x, list *matrix)
{
   list *add = (list*)malloc(sizeof(list));
    if(matrix[line].next == NULL){
        add->data = x;
        add->next = NULL;
        matrix[line].next = add;
        matrix[line].data++;
    }else{
        add->data = x;
        add->next = matrix[line].next;
        matrix[line].next = add;
	matrix[line].data++;
    }
}

void swap(int *x, int*y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void sort_print(list *matrix, int vertex)
{
  int i,j,q, max, start;

  for(i = 0; i < vertex; i++){
 
    int cells = (matrix+i)->data;

    if(cells != 1){
      int array[cells];
      for(j = 0; j < cells; j++){
          array[j] = matrix[i].next->data;
          matrix[i].next = (matrix+i)->next->next;
      }
      
      start = 0;
      for(q = start; q < cells; q++){
          max = array[q];
          for(j = start; j < cells; j++){
              if(max < array[j]){
                  max = array[j];
                  swap(&array[j], &array[start]);
              }
          }
          start++;
      }
     
        
        for(j = 0; j < cells; j++){
            if(j == 0)  printf("%d ", array[j]);
            if(j != 0){
                if(array[j] != array[j-1])
                    printf("%d ", array[j]);
            }
        }
        puts("");
    }else if(cells == 1) printf("%d\n",  matrix[i].next->data);
  }//for end
}

int main() {
    int side,vertex;
    scanf("%d %d", &vertex, &side);
    list *matrix = create_matrix(vertex);
    
    int i, j;
    
    int s, t;
    for (i = 0; i < side; i++) {
        scanf("%d %d", &s, &t);
	if(s != t){
	  AdjacencyListTableMake(s, t, matrix);
	  AdjacencyListTableMake(t, s, matrix);
	}else AdjacencyListTableMake(s, t, matrix);
    }
    
    sort_print(matrix, vertex);
    return 0;
}

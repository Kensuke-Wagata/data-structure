#import <stdio.h>
#import <stdlib.h>

typedef struct cell{
    int element;
    struct cell *prev;
    struct cell *next;
}cell;

cell *init = NULL;
cell *final = NULL;

void add_list(int x){
    cell *new = (cell*)malloc(sizeof(cell));
    new->element = x;
    new->next = init;
    new->prev = NULL;
    if(init == NULL) final = new;
    else init->prev = new;
    init = new;
}

int print_list(struct cell *list){
    puts("リスト");
    while(list != NULL){
        printf("%d\n", list->element);
        list = list->next;
    }
    return 0;
}

int main(){
    add_list(1);
    add_list(2);
    add_list(3);
    add_list(4);
    print_list(init);
    return 0;
}


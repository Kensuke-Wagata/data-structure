

#include <stdio.h>
#include <stdlib.h>

typedef struct _stack{
    int element;
    struct _stack *next;
}stack;

// 空のスタックを作成
stack* create() {
    stack *S = (stack *)malloc(sizeof(stack));
    S = (stack *)malloc(sizeof(stack));
    S->next = NULL;
    S->element = -1;
    return S;
}

//先頭に追加
void push(stack *S, int element) {
    stack *add = (stack *)malloc(sizeof(stack));
    add->element = element;
    add->next = S->next;
    S->next = add;
}

//先頭を削除
void pop(stack *S) {
    stack *ptr  = S->next;
    stack *prev = S;
    prev->next = ptr->next;
}


//全てを表示
void print(stack *S) {
    stack *ptr = S->next;
    while(ptr != NULL) {
        printf("%d ", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    stack *S = create();
    
    int number, times = 0;
    int push_pop;
    
    
    while(1) {
        times++;
        if(times <= 1){
            printf("PUSH：1 PRINT：3 END：4\n");
        }else {
            printf("PUSH：1　POP：2 PRINT：3 END：4\n");
        }
        scanf("%d", &push_pop);
        
        if(push_pop == 1){
            printf("数を入力してください : ");
            scanf("%d", &number);
        }
        
        if(push_pop == 1){
            push(S, number);
        }else if(push_pop == 2 && times > 1){
            pop(S);
        }else if(push_pop == 3){
            print(S);
        }else if(push_pop == 4){
            exit(0);
        }else{
            printf("入力が不適切です\n");
        }
    }
    
    return 0;
}


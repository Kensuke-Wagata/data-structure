#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 会員情報を登録する構造体 */

struct LIST{
    unsigned int number;
    char name[256];
    int year;
    struct LIST *next;
} ;

//年齢を降順にソートし、名前を合わせる
void sortList(struct LIST *list)
{
    int mini = list->year;
    char name_tmp[256];
    int year_tmp;

    while(list->next != NULL){
        if( (list->next)->year < mini ){
            mini = (list->next)->year;

            //名前を入れ替える
            strcpy( name_tmp, (list->next)->name );
            strcpy( (list->next)->name, list->name );
            strcpy( list->name, name_tmp );

            //年齢を入れ替える
            year_tmp = (list->next)->year;
            (list->next)->year = list->year;
            list->year = year_tmp;
        }
        list = list->next;
    }
}


/* 会員情報を全て表示する関数 */
int displayList(struct LIST *list){

    puts("現在のリスト");
    while(list != NULL){
        printf("%s %d\n", list->name, list->year);
        list = list->next;
    }
    return 0;
}



/* 会員情報をリストの最後に追加し、リストの先頭アドレスを返却する関数 */
struct LIST* addList(struct LIST *list, char *name, int year){
    struct LIST *item;
    struct LIST *top;

    top = list;

    item = (struct LIST*)malloc(sizeof(struct LIST));
    strcpy(item->name, name);
    item->year = year;
    item->next = NULL;


    /* リストが空の場合は先頭に追加して終了 */
    if(list == NULL){
        list = item;
        return list;
    }

    /* リストのnextを辿ってリストの最後を探す */
    /* リストの最後とは、nextがNULLの要素 */
    while(list->next != NULL){
        list = list->next;
    }
    list->next = item;

    sortList(list);

    /* ここでreturnする場合は先頭アドレスは変わらない */
    return top;
}



/* 会員情報を削除し、リストの先頭アドレスを返却する関数 */
struct LIST* deleteList(struct LIST *list, char *inputname){
    struct LIST *tmp;
    struct LIST *top;
    top = list;

    /* 先頭ノードの場合だけ別処理 */
    if(list != NULL && strcmp( list->name, inputname ) == 0){
        tmp = list->next;
        free(list);

        /* 次の要素のアドレスをリストの先頭アドレスとして返却 */
        return tmp;
    }

    /* リストを辿って指定された会員番号の要素を探す */
    while(list != NULL){
        if( strcmp( list->next->name, inputname ) == 0 ){
            tmp = (list->next)->next;
            free(list->next);
            list->next = tmp;
            return top;
        }

        list = list->next;
    }
    printf("%sが見つかりません\n", inputname);

    return NULL;
}


int main(void){
    char *inputname;
    int inputyear;

    struct LIST *list = NULL;

    printf("氏名と年齢を入力するとそのデータが登録されます\n");
    printf("氏名を「-1」にするとその人が削除されます。\n");
    printf("終わるときは氏名を「END」にしてください。\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    /* 会員登録情報に対する操作 */
    while(1){
        printf("氏名と年齢をスペース区切りで入力してください\n");

        scanf("%s %d", inputname, &inputyear);

        if(strcmp( inputname, "END" ) == 0 ){
            break;
        }else if(inputyear == -1){
            list = deleteList(list, inputname);
        }else {
            list = addList(list, inputname, inputyear);
        }

        displayList(list);
    }
    printf("終わります\n");
    return 0;
}

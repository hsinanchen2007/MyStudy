c语言解法，打败了100%
```c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef char boolean;
#define RELACE 0    //替换节点元素
#define RIGHT 1     //放到右节点
#define IGNORE 2    //忽略
#define LEFT   -1   //左
#define BUFFER_SIZE 1000

typedef struct raxtree raxtree;

struct raxtree {
    raxtree *left; //比较小于前一个的
    raxtree *right; //比较大于前一个
    char *data;     //当前字符串
    int len;        //长度
};
//比较两个字符串，size为当前需要插入或者查询的字符串
boolean compare(char *root, char *now, int size){
    char c1, c2;
    char *root_t = root;
    char *now_t = now;
    while (size){
        c1 = *root_t++;
        c2 = *now_t++;

        if (c1 == c2){
            size--;
            continue;
        }
        
        if (c2 == '\0'){
            return RELACE;
        }
        if (c1 == '\0'){
            return IGNORE;
        }
        if (c1 - c2 > 0){
            return LEFT;
        }
        else {
            return RIGHT;
        }
    }
    return RELACE;
}
//构造raxtree
raxtree * build_raxtree(){
    raxtree *rax = (raxtree *) malloc(sizeof(raxtree));
    rax->left = NULL;
    rax->right = NULL;
    rax->len = -1;
    return rax;
}

//插入元素
void insert(char *data, raxtree *rax, int direct){
    if (direct == LEFT){
        if (rax->left == NULL){
            rax->left = build_raxtree();
        }
        rax = rax->left;
    }
    if (direct == RIGHT){
        if (rax->right == NULL){
            rax->right = build_raxtree();
        }
        rax = rax->right;
    }
    if (rax->len == -1){
        rax->len = strlen(data);
        rax->data = data;
    }
    else {
        int data_size = strlen(data);
        int ret = compare(rax->data, data, data_size);
        if (ret == IGNORE){
            return;
        }
        else if (ret == RELACE){
            rax->len = data_size;
            rax->data = data;
        }
        else if (ret == LEFT){
            insert(data, rax, LEFT);
        }
        else if(ret == RIGHT){
            insert(data, rax, RIGHT);
        }

    }
}
//查找元素
char * find(char *data, raxtree *rax){
    if (rax == NULL){
        return NULL;
    }
    int c = compare(rax->data, data, strlen(data));
    if (c == IGNORE){
        return rax->data;
    }
    else if (c == RELACE){
        return data;
    }
    else if (c == RIGHT){
        return find(data, rax->right);
    }
    else {
        return find(data, rax->left);
    }
}

void freeRaxTree(raxtree *rax){
    if (rax != NULL){
        raxtree *left = rax->left;
        raxtree *right = rax->right;
        free(rax);
        freeRaxTree(left);
        freeRaxTree(right);
    }
}

//替换
char * replaceWords(char ** dict, int dictSize, char * sentence){
    raxtree *rax = build_raxtree();
    for (int i = 0; i < dictSize; i++){
        insert(dict[i], rax, 0);
    }
    printf("strlen(sentence) = %d\n", strlen(sentence));
    char *newSentence = malloc(strlen(sentence) + 1);
    memset(newSentence, 0x20, strlen(sentence) + 1);
    char *retVal = newSentence;
    char c = *sentence++;
    char buffer[BUFFER_SIZE + 1];
    int i = 0;
    int j = 0;
    int n = 0;
    while (c != '\0'){
        if (c == ' '){
            while (c == ' '){
                c = *sentence++;
                j++;
            }
            if (i != 0){
                buffer[i] = '\0';
                char * fret = find(buffer, rax);
                if (fret == NULL){
                    memcpy(newSentence, buffer, i);
                    newSentence = newSentence + i;
                }
                else {
                    //printf("newSentence = %p, newSentence + n = %p\n", newSentence, newSentence + n);
                    memcpy(newSentence, fret, strlen(fret));
                    newSentence = newSentence + strlen(fret);
                }
                while(j > 0){
                    newSentence++;
                    j--;
                }
            }
            i = 0;
        }
        buffer[i++] = c;
        c = *sentence++;
    }
    if (i != 0){
        buffer[i] = '\0';
        char * fret = find(buffer, rax);
        if (fret == NULL){
            memcpy(newSentence, buffer, i);
            newSentence = newSentence + i;
        }
        else {
            //printf("newSentence = %p, newSentence + n = %p\n", newSentence, newSentence + n);
            memcpy(newSentence, fret, strlen(fret));
            newSentence = newSentence + strlen(fret);
        }
    }
    freeRaxTree(rax);
    *newSentence = '\0';
    return retVal;
}
```c

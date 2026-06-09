### 解题思路
C手写栈，超过双百

### 代码

```c
typedef struct SNode* PtrToSNode;
struct SNode {
    char* str;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->str = NULL;
    S->next = NULL;
    return S;
}

bool Add(Stack S)
{
    PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    tmp->str = (char*)malloc(3000*sizeof(char));
    memset(tmp->str, '\0', 3000*sizeof(char));
    tmp->next = S->next;
    S->next = tmp;
    return true;
}

bool IsEmpty(Stack S)
{
    return (S->next == NULL);
}

char* Top(Stack S)
{
    if (IsEmpty(S)) {
        return NULL;
    }
    PtrToSNode firstnode = S->next;
    return firstnode->str;
}

bool Pop(Stack S)
{
    if (IsEmpty(S)) {
        return false;
    }
    PtrToSNode firstnode = S->next;
    S->next = firstnode->next;
    firstnode->next = NULL;
    free(firstnode);
    return true;
}


char * decodeString(char * s){
    int sLen = strlen(s);
    //用来记录倍数关系的
    int* times = (int*)malloc(50*sizeof(int));
    memset(times, 0, 50*sizeof(int));
    int timesLen = 0;
    // 用来转换成int
    char* time = (char*)malloc(11*sizeof(char));
    memset(time, '\0', 11*sizeof(char));
    
    Stack S = CreateStack();
    Add(S);
    
    for (int i = 0; i < sLen; i++) {
        if (isdigit(s[i])) {
            time[strlen(time)] = s[i];
        }
        else if (s[i] == '[') {
            int count = atoi(time);
            memset(time, '\0', 11*sizeof(char));
            times[timesLen] = count;
            timesLen++;
            Add(S);
        }
        else if (isalpha(s[i])) {
            Top(S)[strlen(Top(S))] = s[i];
        }
        else if (s[i] == ']') {
            char* str = (char*)malloc(3000*sizeof(char));
            memset(str, '\0', 3000*sizeof(char));
            strcpy(str, Top(S));
            Pop(S);
            int strcount = times[timesLen - 1];
            //printf("%d\n",strcount);
            times[timesLen - 1] = 0;
            timesLen--;
            for (int i = 0; i < strcount; i++) {
                strcat(Top(S), str);
            }
        }
        //printf("%d\n",i);
        //puts(Top(S));
    }
    return Top(S);
}









```
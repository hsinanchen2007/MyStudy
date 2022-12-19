```
typedef struct SNode* PtrToSNode;
struct SNode{
    char* data;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

Stack CreateStack(){
    Stack S = (PtrToSNode)malloc(sizeof(struct SNode));
    S->next = NULL;
    return S;
}

bool IsEmpty(Stack S){
    return (S->next == NULL);
}

bool Push(Stack S, char* s){
    PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    tmp->data = s;
    tmp->next = S->next;
    S->next = tmp;
    return true;
}

bool Pop(Stack S){
    if(IsEmpty(S)){
        return false;
    }
    PtrToSNode firstnode = S->next;
    S->next = firstnode->next;
    free(firstnode);
    return true;
}

char* Top(Stack S){
    if(IsEmpty(S)){
        return NULL;
    }
    return (S->next->data);
}

Stack Reverse(Stack S){
    Stack S1 = CreateStack();
    PtrToSNode tmp = S;
    while(tmp->next != NULL){
        Push(S1, tmp->next->data);
        tmp = tmp->next;
    }
    return S1;
}

char* simplifyPath(char * path){
    Stack S = CreateStack();
    char* next_token = NULL;
    char* pa = strtok(path, "/");
    while(pa != NULL){
        if(strcmp(pa, "..") == 0){
            Pop(S);
        }
        else if(strcmp(pa, ".") == 0){
        }
        else{
            Push(S, pa);
        }
        pa = strtok(NULL, "/");
    }
    
    Stack S1 = Reverse(S);
    PtrToSNode ptr = S1;
    
    char ans[1000];
    strcpy(ans,"/");
    while(ptr->next != NULL){
        const char* top = ptr->next->data;
        strcat(ans, top);
        if(ptr->next->next != NULL){
            strcat(ans, "/");
        }
        ptr = ptr->next;
    }
    char* ans1 = ans;
    return ans1;
}
```

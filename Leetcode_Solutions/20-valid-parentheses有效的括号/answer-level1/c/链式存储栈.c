- 最后要判断栈是否为空
- 出栈的时候需要指针是否为空
- switch case 需要break
```
typedef struct Stack{
    char data;
    struct Stack* next;
}MyStack;

MyStack* MyCreateStack(){
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj -> next = NULL;
    return obj;
}

void myStackPush(MyStack* obj, char s){
    MyStack* node = (MyStack*)malloc(sizeof(MyStack));
    node -> data = s;
    node -> next =  obj -> next;
    obj -> next = node;
}

void myStackPop(MyStack* obj){
    MyStack* node = obj -> next;
    obj -> next = obj -> next -> next;
    free(node);
}

char myStackTop(MyStack* obj){
    if(obj -> next != NULL){
        return obj -> next -> data;
    }
    return NULL;
}
bool isValid(char * s){
    int len = strlen(s);
    MyStack* obj = MyCreateStack();
    for(int i = 0; i < len; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            myStackPush(obj, s[i]);
        }else{
            switch(s[i]){
                case ')' :
                    if(myStackTop(obj) == '('){
                        myStackPop(obj);
                        break;
                    }else{
                        return false;
                    }
                case ']' :
                    if(myStackTop(obj) == '['){
                        myStackPop(obj);
                        break;
                    }else{
                        return false;
                    }
                case '}' :
                    if(myStackTop(obj) == '{'){
                        myStackPop(obj);
                        break;
                    }else{
                        return false;
                    }
            }
        }
    }
    if(obj -> next != NULL){
        return false;
    }
    return true;
}
```

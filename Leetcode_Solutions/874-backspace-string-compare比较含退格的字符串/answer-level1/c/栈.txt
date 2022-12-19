### 解题思路
字母进栈， #出栈，

### 代码

```c
typedef struct {
    int top;
    char* Stack;
}CStack;

CStack* stackCreate()
{
    CStack* obj = (CStack*)malloc(sizeof(CStack));
    obj->top = -1;
    obj->Stack = (char*)malloc(sizeof(char) * 200);
    return obj;
}

void pushStack(CStack* obj, char c) 
{
    if (obj->top >= 200) {
        return;
    }
    obj->Stack[++obj->top] = c;
}

char popStack(CStack* obj)
{
    if (obj->top == -1) {
        return -1;
    }
    return obj->Stack[obj->top--];
}

void freeStack(CStack* obj)
{
    free(obj->Stack);
    obj->Stack = NULL;
    free(obj);
    obj = NULL;
}

bool backspaceCompare(char * S, char * T){

    CStack* Sobj = stackCreate();
    CStack* Tobj = stackCreate();
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] != '#') {
            pushStack(Sobj, S[i]);
        } else {
            popStack(Sobj);
        }
    }
    printf("%d %d\n", Sobj->top, Tobj->top);
    for (int i = 0; i < strlen(T); i++) {
        if (T[i] != '#') {
            pushStack(Tobj, T[i]);
        } else {
            popStack(Tobj);
        }
    }
    printf("%d %d", Sobj->top, Tobj->top);
    if (Sobj->top == -1 && Tobj->top == -1) {
        return true;
    }
    if (Sobj->top != Tobj->top) {
        return false;
    }
    for (int i = Sobj->top; i >= 0; i--) {
        if (Sobj->Stack[i] != Tobj->Stack[i]) {
            return false;
        }
    }
    return true;
}
```
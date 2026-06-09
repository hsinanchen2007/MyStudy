申请两个栈空间，栈1存括号，栈2存星号；
从左到右和从右到左各匹配一次，先把对应括号的配额用掉，没有了再用星号，两种配额都没有则肯定不行，返回FALSE；
如果两个方向都没有直接返回FALSE，则说明星号是够用的。

```
#define TRUE    1
#define FALSE   0

typedef struct {
    char*   data;
    int     top;
    int     size;
} myStack;

myStack* initStack(int sizeStack)
{
    myStack* obj = NULL;

    obj = (myStack*)malloc(sizeof(myStack));

    if (obj != NULL) {
        obj->top = -1;
        obj->data = (char*)malloc(sizeStack);
        if (obj->data == NULL) {
            free(obj);
            return NULL;
        }
        obj->size = sizeStack;
    }

    return obj;
}

void myPush(myStack* obj, char x)
{
    obj->top += 1;
    obj->data[obj->top] = x;
}

char myPop(myStack* obj)
{
    char top = obj->data[obj->top];
    obj->top -= 1;
    return top;
}

char GetTop(myStack* obj)
{
    return obj->data[obj->top];
}

bool StatckEmpty(myStack* obj)
{
    return (obj->top == -1);
}

void ClearStack(myStack* obj)
{
    memset(obj->data, 0, obj->size);
    obj->top = -1;
}

void DestroyStack(myStack* obj)
{
    free(obj->data);
    free(obj);
}

bool checkValidString(char * s){
    if (s == NULL) {
        return TRUE;
    }

    int strLen = strlen(s);

    myStack* obj1;
    myStack* obj2;
    obj1 = initStack(strLen);
    obj2 = initStack(strLen);

    int i;
    for (i = 0; i < strLen; i++) {
        if (s[i] == '(') {
            myPush(obj1, s[i]);
            continue;
        }

        if (s[i] == '*') {
            myPush(obj2, s[i]);
            continue;
        }

        if (s[i] == ')') {
            if (StatckEmpty(obj1) && StatckEmpty(obj2)) {
                DestroyStack(obj1);
                DestroyStack(obj2);
                return FALSE;
            }

            if (!StatckEmpty(obj1)) {
                myPop(obj1);
                continue;
            } else {
                myPop(obj2);
                continue;
            }
        }
    }

    ClearStack(obj1);
    ClearStack(obj2);

    for (i = strLen - 1; i >= 0; i--) {
        if (s[i] == ')') {
            myPush(obj1, s[i]);
            continue;
        }

        if (s[i] == '*') {
            myPush(obj2, s[i]);
            continue;
        }

        if (s[i] == '(') {
            if (StatckEmpty(obj1) && StatckEmpty(obj2)) {
                DestroyStack(obj1);
                DestroyStack(obj2);
                return FALSE;
            }

            if (!StatckEmpty(obj1)) {
                myPop(obj1);
                continue;
            } else {
                myPop(obj2);
                continue;
            }
        }
    }

    DestroyStack(obj1);
    DestroyStack(obj2);
    return TRUE;
}
```




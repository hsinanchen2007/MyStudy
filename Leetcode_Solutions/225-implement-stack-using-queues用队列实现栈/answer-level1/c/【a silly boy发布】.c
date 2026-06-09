![image.png](https://pic.leetcode-cn.com/5c2a089748db4eab8f0e44a85b2ac048b5efc1070d415d60782e963e9731afb0-image.png)

```
typedef struct {
    int val;
    struct MyStack *next;
} MyStack;

bool g_isFirst = false;

MyStack* myStackCreate() 
{
    MyStack* obj = (MyStack *)malloc(sizeof(MyStack));
    obj->next = NULL;
    g_isFirst = false;
    return obj;
}

void myStackPush(MyStack* obj, int x) 
{
    MyStack *tmpObj = obj;
    
    if (g_isFirst == false) {
        obj->val = x;
        obj->next = NULL;
        g_isFirst = true;
        return;
    }
    while (tmpObj->next != NULL) {
        tmpObj = tmpObj->next;
    }
    tmpObj->next = (MyStack *)malloc(sizeof(MyStack));
    tmpObj = tmpObj->next;
    tmpObj->val = x;
    tmpObj->next = NULL;
    return;
}

int myStackPop(MyStack* obj) 
{
    MyStack *tmpObj = obj;
    MyStack *tmp1Obj = obj;
    
    int returnVal;
    if ((obj == NULL) || (g_isFirst == false)) {
        return 0;
    }
    if (obj->next == NULL) {
        returnVal = obj->val;
        g_isFirst = false;
        obj = NULL;
        return returnVal;
    } else {
        while (tmpObj->next != NULL) {
            tmp1Obj = tmpObj;
            tmpObj = tmpObj->next;
        }
        returnVal = tmpObj->val;
        free(tmpObj);
        tmp1Obj->next = NULL;
        return returnVal;
    }
}

int myStackTop(MyStack* obj) 
{
    int returnVal = 0;
    MyStack *tmpObj = obj;
    if (obj == NULL) {
        return returnVal;
    } else {
        while (tmpObj->next != NULL) {
            tmpObj = tmpObj->next;
        }
        returnVal = tmpObj->val;
        return returnVal;
    }
}

bool myStackEmpty(MyStack* obj) 
{
    if ((obj == NULL) || (g_isFirst == false)) {
        return true;
    } else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    if (obj != NULL) {
        free(obj);
    }
}
```

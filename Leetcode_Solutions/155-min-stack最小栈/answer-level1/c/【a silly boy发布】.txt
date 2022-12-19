![F55DFDBB-1A14-4A3D-B78B-631CD63D3081.jpeg](https://pic.leetcode-cn.com/0a7a2ddd3d4c223c0a1b5058cac3cfa9cb1a0dfb81dfaa144bb5030644dfe953-F55DFDBB-1A14-4A3D-B78B-631CD63D3081.jpeg)

```
#define MAXSIZE 8000

typedef struct {
    int val[MAXSIZE];
    int minVal[MAXSIZE];
    int valNum;
} MinStack;

int Cmp(const void *a, const void *b)
{
    long long int tmp;
    tmp = (long long int)(*(int *)a) - (long long int)(*(int *)b);
    return (tmp == 0) ? 0 : (tmp > 0 ? 1 : -1);
}

MinStack* minStackCreate() 
{
    MinStack *minStack = (MinStack *)malloc(sizeof(MinStack));
    minStack->valNum = 0;
    return minStack;
}

void minStackPush(MinStack* obj, int x) 
{
    obj->val[obj->valNum] = x;
    if (obj->valNum == 0) {
        obj->minVal[obj->valNum] = x;
    } else {
        if (obj->minVal[obj->valNum - 1] > x) {
            obj->minVal[obj->valNum] = x;   
        } else {
            obj->minVal[obj->valNum] = obj->minVal[obj->valNum - 1];   
        }
    }
    obj->valNum++;
}

void minStackPop(MinStack* obj) 
{
    if (obj->valNum != 0) {
        obj->valNum--;
    }
}

int minStackTop(const MinStack* obj) 
{
    if (obj->valNum > 0) {
        return (int)(obj->val[obj->valNum - 1]);
    } else {
        return 0;
    }
}

int minStackGetMin(const MinStack* obj) 
{
    int returnVal = 0;
    if (obj->valNum - 1 >= 0) {
        returnVal = obj->minVal[obj->valNum - 1];
    }
    return returnVal;
}

void minStackFree(MinStack* obj) 
{
    obj->valNum = 0;
    free(obj);
}
```

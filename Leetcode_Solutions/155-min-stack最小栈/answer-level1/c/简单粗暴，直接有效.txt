在push中和最小元素比较
在pop中重新查找最小元素

执行用时 :40 ms, 在所有 C 提交中击败了63.77% 的用户
内存消耗 :12.3 MB, 在所有 C 提交中击败了100.00%的用户

```c []
typedef struct
{
    int *data;
    int size;
    int cap;
    int min;
} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate()
{
    MinStack *obj = malloc(sizeof(MinStack));
    memset(obj, 0, sizeof(MinStack));
    return obj;
}
static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
static void shiftUp(int *data, int pos)
{
    for (; data[pos] < data[pos / 2] && pos >= 0;)
    {
        swap(data + pos, data + pos / 2);
        pos /= 2;
    }
}
void minStackPush(MinStack *obj, int x)
{
    if (obj->cap == obj->size)
    {
        obj->cap = (obj->cap + 1) * 2;
        obj->data = realloc(obj->data, sizeof(int) * obj->cap);
    }
    if (obj->size == 0)
    {
        obj->min = x;
    }
    obj->data[obj->size++] = x;
    if (x < obj->min)
        obj->min = x;
}

static minUp(int *data, int size)
{
    for (int i = 0; i < size;)
    {
        if (data[i * 2 + 1] < data[i * 2 + 2])
        {
            swap(data + i, data + i * 2 + 1);
            i = i * 2 + 1;
        }
        else
        {
            swap(data + i, data + i * 2 + 2);
            i = i * 2 + 2;
        }
    }
}
static int findMin(int *data, int size)
{
    int min;
    for (int i = 0; i < size; ++i)
    {
        if (i)
        {
            if (data[i] < min)
                min = data[i];
        }
        else
        {
            min = data[i];
        }
    }
    return min;
}
void minStackPop(MinStack *obj)
{
    obj->size--;
    if (obj->data[obj->size] == obj->min)
    {
        obj->min = findMin(obj->data, obj->size);
    }
}

int minStackTop(MinStack *obj)
{
    return obj->data[obj->size - 1];
}

int minStackGetMin(MinStack *obj)
{
    return obj->min;
}

void minStackFree(MinStack *obj)
{
    free(obj->data);
    free(obj);
}
```

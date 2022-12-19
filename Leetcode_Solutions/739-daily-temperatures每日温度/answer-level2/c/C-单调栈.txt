### 解题思路
使用单调栈。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_STACK_SIZE 1002
typedef int stack_elem_t; // 元素的类型
/**
* @struct
* @brief 栈的结构体
*/
typedef struct stack_t {
    int size; /** 实际元素个数*/
    int capacity; /** 容量，以元素为单位*/
    stack_elem_t elems[MAX_STACK_SIZE]; /** 栈的数组*/
} stack_t;

stack_t g_stack;
/**
* @brief 创建栈.
* @param[in] capacity 初始容量
* @return 栈对象的指针
*/
stack_t* stack_create(void) {
    stack_t *s = &g_stack;
    s->size = 0;
    s->capacity = MAX_STACK_SIZE;
    return s;
}

/**
* @brief 判断栈是否为空.
* @param[in] s 栈对象的指针
* @return 是空，返回1，否则返回0
*/
int stack_empty(const stack_t *s) {
    return s->size == 0;
}
/**
* @brief 获取元素个数.
* @param[in] s 栈对象的指针
* @return 元素个数
*/
int stack_size(const stack_t *s) {
    return s->size;
}
/**
* @brief 进栈.
* @param[in] s 栈对象的指针
* @param[in] x 要进栈的元素
* @return 无
*/
void stack_push(stack_t *s, const stack_elem_t x)
{
    s->elems[s->size++] = x;
}
/**
* @brief 进栈.
* @param[in] s 栈对象的指针
* @return 无
*/
void stack_pop(stack_t *s) {
    s->size--;
}
/**
* @brief 获取栈顶元素.
* @param[in] s 栈对象的指针
* @return 栈顶元素
*/
stack_elem_t stack_top(const stack_t *s) {
    return s->elems[s->size - 1];
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    if (T == NULL) {
        * returnSize = 0;
        return NULL;
    }
    int *returnT;
    int T_temp[TSize];
    stack_t *s = stack_create();//初始化栈s
    int i, j, k;
    returnT = (int *)malloc(sizeof(int) * (TSize + 1));
    memset(returnT, 0, sizeof(int) * (TSize + 1));
    if (TSize == 1) {
        * returnSize = 1;
        return returnT;
    }
    for (i = TSize - 1; i >= 0; i--) {
        while (!stack_empty(s) && stack_top(s) <= T[i]) {
            stack_pop(s);
        }
        T_temp[i] = stack_empty(s) ? 0 : stack_top(s);
        returnT[i] = i;
        stack_push(s, T[i]);
    }

    for (i = 0; i < TSize; i++) {
        k = 0;
        if (T_temp[i] == 0) {
            returnT[i] = T_temp[i];
            continue;
        }
        while (T[i + k] != T_temp[i]) {
            k++;
        }
        returnT[i] = k;
    }

    * returnSize = TSize;
    return returnT;
}
```
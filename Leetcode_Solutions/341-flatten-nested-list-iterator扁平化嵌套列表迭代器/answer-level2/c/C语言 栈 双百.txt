题的用例有很多坑，尤其是[[[[]]],[]]这种，不知道谁想出来的，真是......
用栈倒序保存，内存动态重规划即可。
执行结果：通过
显示详情
执行用时 :12 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :11.8 MB, 在所有 C 提交中击败了100.00%的用户
```
*
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedIterator {
    int len;
    int top;
    struct NestedInteger **stack;
};
struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize)
{
    struct NestedIterator *iter = calloc(1, sizeof(struct NestedIterator));
    iter->stack = calloc(nestedListSize, sizeof(struct NestedInteger*));
    for (int i = 0; i < nestedListSize; i++) {
        iter->stack[i] = nestedList[nestedListSize - 1 - i];
        iter->top++;
    }
    iter->len = nestedListSize;
    return iter; 
}
bool nestedIterHasNext(struct NestedIterator *iter)
{
    if (iter->top <= 0) {
        return false;
    }
    if (NestedIntegerIsInteger(iter->stack[iter->top - 1]) == true) {
        return true;
    }
    struct NestedInteger **nestedList;
    int len;
    while ((iter->top > 0) && (NestedIntegerIsInteger(iter->stack[iter->top - 1]) != true)) {
        nestedList = NestedIntegerGetList(iter->stack[iter->top - 1]);
        len = NestedIntegerGetListSize(iter->stack[iter->top - 1]);
        if (iter->top + len > iter->len) { /* 内存重分配，没做保护，默认为不会重分配失败 */
            iter->len = iter->top + len;
            iter->stack = realloc(iter->stack, iter->len * sizeof(struct NestedInteger*));
        }
        iter->top--;  /* 当前容器出栈拆分重新压栈 */
        for (int i = 0; i < len; i++) {
            iter->stack[iter->top++] = nestedList[len - 1 - i];
        }
    }
    if ((iter->top > 0) && (NestedIntegerIsInteger(iter->stack[iter->top - 1]) == true)) {
        return true;
    }
    return false;
}
int nestedIterNext(struct NestedIterator *iter)
{
    iter->top--;
    return NestedIntegerGetInteger(iter->stack[iter->top]);
}
/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter)
{
    free(iter->stack);
    free(iter);
}
/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */
```

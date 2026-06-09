### 解题思路
C+栈解题，栈要理清储存元素是什么

### 代码

```c
/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
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

typedef struct SNode* PtrToSNode;
struct SNode {
    struct NestedInteger* Nested;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->next = NULL;
    return S;
}

bool Push(Stack S)
{
    PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    tmp->Nested = NestedIntegerInit();
    tmp->next = S->next;
    S->next = tmp;
    return true;
}

bool IsEmpty(Stack S)
{
    return (S->next == NULL);
}

struct NestedInteger* Top(Stack S)
{
    if (IsEmpty(S)) {
        return NULL;
    }
    else {
        return S->next->Nested;
    }
}

bool Pop(Stack S) {
    if (IsEmpty(S)) {
        return false;
    }
    else {
        PtrToSNode firstnode = S->next;
        S->next = firstnode->next;
        firstnode->next = NULL;
        return true;
    }
}

struct NestedInteger* deserialize(char * s){
    struct NestedInteger* res = (struct NestedInteger*)malloc(sizeof(struct NestedInteger));
    
    // 如果仅仅包含一个数字
    if (isdigit(s[0]) || s[0] == '-') {
        int n = atoi(s);
        NestedIntegerSetInteger(res, n);
        return res;
    }

    // 包含列表
    Stack NestedS = CreateStack();
    int sLen = strlen(s);
    char* num = (char*)malloc((sLen - 1)*sizeof(char));   // 用来存数字
    memset(num, '\0', (sLen - 1)*sizeof(char));
    int numLen = 0;
    for (int i = 0; i < sLen; i++) {
        if (s[i] == '[') {
            Push(NestedS);
        }
        else if (isdigit(s[i]) || s[i] == '-') {
            num[numLen] = s[i];
            numLen++;
        }
        else if (s[i] == ',') {
            if (strlen(num) != 0) {
                int n = atoi(num);
                struct NestedInteger* tmp = (struct NestedInteger*)malloc(sizeof(struct NestedInteger));
                NestedIntegerSetInteger(tmp, n);
                struct NestedInteger* top = Top(NestedS);
                NestedIntegerAdd(top, tmp);
                memset(num, '\0', (sLen - 1)*sizeof(char));
                numLen = 0;
            }
        }
        else if (s[i] == ']') {
            struct NestedInteger* topCur = Top(NestedS);
            if (strlen(num) != 0) {
                int n = atoi(num);
                struct NestedInteger* tmp = (struct NestedInteger*)malloc(sizeof(struct NestedInteger));
                NestedIntegerSetInteger(tmp, n);
                NestedIntegerAdd(topCur, tmp);
                memset(num, '\0', (sLen - 1)*sizeof(char));
                numLen = 0;
            }
            Pop(NestedS);
            struct NestedInteger* topNext = Top(NestedS);
            if (topNext != NULL) {
                NestedIntegerAdd(topNext, topCur);
            }
            else {
                res = topCur;
            }
        }
    }
    return res;
}


```
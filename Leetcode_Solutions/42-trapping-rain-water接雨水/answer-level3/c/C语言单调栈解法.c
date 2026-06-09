```
typedef struct SNode* PtrToSNode;
struct SNode{
    int val;
    int index;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S = (PtrToSNode)malloc(sizeof(struct SNode));
    S->next = NULL;
    return S;
}

bool Push(Stack S, int val, int index)
{
    PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    tmp->val = val;
    tmp->index = index;
    tmp->next = S->next;
    S->next = tmp;
    return true;
}

bool IsEmpty(Stack S)
{
    return (S->next == NULL);
}

PtrToSNode Top(Stack S)
{
    if (IsEmpty(S)) {
        return NULL;
    }
    PtrToSNode firstnode = S->next;
    return firstnode;
}

PtrToSNode Pop(Stack S)
{
    if (IsEmpty(S)) {
        return NULL;
    }
    PtrToSNode firstnode = S->next;
    S->next = firstnode->next;
    firstnode->next = NULL;
    return firstnode;
}

int trap(int* height, int heightSize)
{
    if (heightSize < 3) {
        return 0;
    }
    Stack S = CreateStack();
    Push(S, height[0], 0);
    int TNHeight = 0;
    int water = 0;
    for (int i = 1; i < heightSize; i++) {
        if (Top(S)->val >= height[i]) {
            Push(S, height[i], i);
        }
        else {
            while (!IsEmpty(S) && Top(S)->val < height[i]) {
                TNHeight = Pop(S)->val;
                if (!IsEmpty(S)) {
                    int waterHeight = fmin(height[i], Top(S)->val) - TNHeight;
                    water += (i - Top(S)->index - 1)*waterHeight;
                }
            }
            Push(S, height[i], i);
        }
    }
    return water;
}
```
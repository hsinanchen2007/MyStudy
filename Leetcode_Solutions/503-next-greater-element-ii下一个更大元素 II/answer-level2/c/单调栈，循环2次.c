单调栈，循环2次，第2次的时候，不压栈。
```


typedef struct tagNode {
    int idx;
    int val;
} Node_S;

typedef struct tagStack {
    Node_S *data;
    int num;
    int top;
} Stack_S;

int push(Stack_S *st, int val, int idx)
{
    if (st->top == -1) {
        st->data[0].idx = idx;
        st->data[0].val = val;
        st->top = 0;
    } else {
        ++st->top;
        st->data[st->top].idx = idx;
        st->data[st->top].val = val;
    }
    return 0;
}

int pop(Stack_S *st, int *val, int *idx)
{
    if (st->top == -1) {
        return -1;
    }
    if (val) {
        *val = st->data[st->top].val;
    }
    if (idx) {
        *idx = st->data[st->top].idx;
    }
    --st->top;
    return 0;
}

Stack_S* init(int num) 
{
    Stack_S *st = (Stack_S*)malloc(sizeof(Stack_S) + sizeof(Node_S) * num);
    if (st == NULL) {
        return NULL;
    }
    st->data = (Node_S *)(st + 1);
    st->top = -1;
    st->num = num;
    return st;
}

bool IsEmpty(Stack_S *st) 
{
    if (st->top == -1) {
        return true;
    }
    return false;
}

int topval(Stack_S *st) 
{
    return st->data[st->top].val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    Stack_S *st = init(numsSize);
    if (st == NULL) {
        return NULL;
    }
    
    int *nexts = (int*)malloc(sizeof(int) * numsSize);
    if (nexts == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize * 2; i++) {
        int k = i % numsSize;
        //printf("k = %d, val %d\n", k, nums[k]);
        while (!IsEmpty(st) && topval(st) < nums[k]) {
            int idx;
            int val;
            (void)pop(st, &val, &idx);
            //printf("pop val %d, idx:%d\n", val, idx);
            nexts[idx] = nums[k];    
        }
        if (i == k) {
            //printf("push val %d, idx %d\n", nums[k], k);
            push(st, nums[k], k);
        }

    }
    while (!IsEmpty(st)) {
        int k;
        pop(st, NULL, &k);
        nexts[k] = -1;
    }
    (void)free(st);
    *returnSize = numsSize;
    return nexts;
}
```
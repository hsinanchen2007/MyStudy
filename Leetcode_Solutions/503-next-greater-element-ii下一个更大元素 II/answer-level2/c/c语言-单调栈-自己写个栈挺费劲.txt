![image.png](https://pic.leetcode-cn.com/0d772473dc1deb523420598c827e1e17156315b11a40dad48538959e7da74f7e-image.png)

相比c++可以使用的大量的库，c语言开发效率要低多了。想用栈自己写，挺费劲。

```c

#define MAX_NUMS 20000

typedef struct Node {
    int index;
    int val;
}Node;

typedef struct Stack {
    Node pool[MAX_NUMS];
    int top;
}Stack;

Stack g_stack = {0};

#define EOK 0
#define ERR -1

void sInit() {
    g_stack.top = -1;
}

int sPush(int index, int val) {
    if(g_stack.top >= MAX_NUMS - 1) {
        return ERR;
    }
    g_stack.pool[g_stack.top+1].index = index;
    g_stack.pool[g_stack.top+1].val = val;
    g_stack.top++;
    return EOK;
}

void sPop() {
    if(g_stack.top < 0) {
        g_stack.top = -1;
        return;
    }
    g_stack.top--;
}

bool sEmpty() {
    return (g_stack.top < 0);
}

int sGetTop(Node* node) {
    if(sEmpty()) {
        return ERR;
    }
    if(node == NULL) {
        return ERR;
    }
    node->index = g_stack.pool[g_stack.top].index;
    node->val = g_stack.pool[g_stack.top].val;
    return EOK;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* ret = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++) {
        ret[i] = -1;
    }

    sInit();

    (void)sPush(0, nums[0]);

    for(int i = 1; i < numsSize * 2  - 1; i++) {
        int idx = i % numsSize;
        while(!sEmpty()) {
            Node topNode = {0};
            (void)sGetTop(&topNode);
            if(topNode.val < nums[idx]) {
                ret[topNode.index] = nums[idx];
                sPop();
            } else {
                break;
            }
        }
        sPush(idx, nums[idx]);
    }

    *returnSize = numsSize;

    return ret;
}
```

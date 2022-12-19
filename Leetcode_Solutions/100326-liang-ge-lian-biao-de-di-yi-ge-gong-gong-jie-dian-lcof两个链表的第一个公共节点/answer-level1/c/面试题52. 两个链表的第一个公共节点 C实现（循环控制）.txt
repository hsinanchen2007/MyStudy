### 解题思路
    将链表节点的地址存入数组从后往前依次比较地址，这题的val不重要甚至可以说不需要。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

int GetLinkedListSize(node* head)
{
    int size = 0;
    while (head) {
        head = head->next;
        size++;
    }
    return size;
}

inline void SetPtrArr(node** p, node* head)
{
    int index = 0;
    while (head) {
        p[index] = head;
        index++;
        head = head->next;
    }
    return;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }
    int sizeA = GetLinkedListSize(headA);
    int sizeB = GetLinkedListSize(headB);
    node** pA = (node**)malloc(sizeof(node*) * sizeA);
    node** pB = (node**)malloc(sizeof(node*) * sizeB);
    SetPtrArr(pA, headA);
    SetPtrArr(pB, headB);
    sizeA--;
    sizeB--;
    bool hasEqual = false;
    while ((sizeA > -1 && sizeB > -1) && pA[sizeA] == pB[sizeB]) {
        hasEqual = true;
        if ((sizeA > 0 && sizeB > 0) && pA[--sizeA] != pB[--sizeB]) {
            return pA[sizeA + 1];
        } else if (sizeA == 0 || sizeB == 0) {
            if (pA[sizeA] != pB[sizeB]) {
                return NULL;
            } else {
                return pA[sizeA];
            }
        }
    }
    if (!hasEqual) {
        return NULL;
    }
    if(sizeB > sizeA) {
        return pA[0];
    }
    return pB[0];
}
```
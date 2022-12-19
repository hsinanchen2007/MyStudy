### 解题思路

    方法很笨但是很直接，逆置链表再遍历一遍就完事了。当然，逆置链表有更好的写法，这里是最笨的写法==
    主要使用了三个指针，p和q是每次需要交换顺序的节点，r指向q->next用来保存下一次需要交换顺序的节点。此外还需要注意判空。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //retrunSize是你要返回的内存数量
typedef struct ListNode List;
int* reversePrint(struct ListNode* head, int* returnSize)
{
    if(!head)
    {
        *returnSize = 0;
        return NULL;
    }
    int* array = (List*)malloc(10005 * sizeof(int*));
    List *p,*q,*r;
    p = head;
    q = p->next;
    p->next = NULL;
    if(!q)
    {
        array[0] = head->val;
        *returnSize = 1;
        return array;
    }
    r = q->next;
    while(r)
    {
        q->next = p; //reverse
        p = q;
        q = r;
        r = q->next;
    }
    q->next = p;
    List *h = q;
    int i = 0;
    while(h)
    {
        array[i] = h->val;
        i++;
        h = h->next;
    }
    *returnSize =i;
    //printf("%d\n",i);
    return array;
}
```
### 解题思路
第一遍遍历获链表的长度，然后计算出中间元素所在的位置进行第二遍遍历即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p,*h;
    int n = 1;
    p = head;
    while(p)
    {
        n++;
        p = p->next;
    }
    if(n == 1)
        return head;
    h = head;
    if(n % 2 == 0)
        n = (n - 1)/2;
    else
    {
        n = n / 2;
    }
    while(n)
    {
        n--;
        h = h->next;
    }
    return h;
}
```
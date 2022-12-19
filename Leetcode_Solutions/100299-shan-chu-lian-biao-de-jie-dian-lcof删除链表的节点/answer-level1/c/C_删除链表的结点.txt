### 解题思路
链表没有头结点，就不好统一处理。单独判断一下头结点即可。及时返还值可以加速。
![image.png](https://pic.leetcode-cn.com/7bf172d1a9594464f88fecf45a6d7239e9be3e1ef4604e68365e5ab349c608b4-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head->val==val)
    {
        head=head->next;
        return head;
    }    
    for(struct ListNode* iter=head;iter->next!=0;iter=iter->next)
        if(iter->next->val==val)
            {
                iter->next=iter->next->next;
                return head;
            }
    return head;
}
```
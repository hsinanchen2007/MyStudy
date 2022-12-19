### 解题思路
此处撰写解题思路
借鉴：
![TIM截图20200409194631.png](https://pic.leetcode-cn.com/8fef9c4d752fc47a85db349898371a2bc658fd22c3ef721301b6170a1f54289c-TIM%E6%88%AA%E5%9B%BE20200409194631.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverse(struct ListNode *head,struct ListNode *tail)
{
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;
    while(head != tail)
    {
        next = head ->next;
        head ->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
struct ListNode*reverseKGroup(struct ListNode* head, int k)
{
    if(head == NULL || head ->next == NULL)
        return head;
    struct ListNode *newHead,*tail = head;
    int i;
    for(i = 0;i < k;i++)
    {
        //剩余数量小于k的话，不需要反转
        if(tail == NULL)
            return head;
        tail = tail ->next;
    }
    //反转前K个元素
    newHead = reverse(head,tail);
    //下一轮的开始的地方就是tail
    head ->next = reverseKGroup(tail,k);

    return newHead;
}
```
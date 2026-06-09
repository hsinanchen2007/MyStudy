### 解题思路
总结一下链表做题的心得：
```
1.考虑链表是否要插入元素，删除需要得到每一个节点的前驱pre

2.考虑链表是否要删除元素，删除元素需要保存元素的后继，以防找不到

3.插入的时候考虑是头插法还是尾插法

4.如果对于一个链表本身进行头插法需要注意插入的元素不能包括它本身，这里给了例题[分割链表](https://leetcode-cn.com/problems/partition-list-lcci/solution/chun-cjie-jue-partition-list-lcci-by-wei-ai-mai-xi/)
```

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1=l1,*p2=l2,*p3,*r;
    int remainder=0;
    int num;

    //for returnList
    struct ListNode *head;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    remainder=0;
    num=(p1?p1->val:0)+(p2?p2->val:0)+remainder;
    remainder=0;
    r=head;
    if(num>9)
        {
            remainder=1;
            num-=10;
        }
    head->val=num;
    p1=p1->next;
    p2=p2->next;
    while(p1||p2||remainder)
    {
        p3=(struct ListNode*)malloc(sizeof(struct ListNode));   
        num=(p1!=NULL?p1->val:0)+(p2!=NULL?p2->val:0)+remainder;
        remainder=0;
        if(num>9)
        {
            remainder=1;
            num-=10;
        }
        p3->val=num;
        r->next=p3;
        r=r->next;
        if(p1)
        p1=p1->next;
        if(p2)
        p2=p2->next;
    }
    r->next=NULL;
    return head;
}
```
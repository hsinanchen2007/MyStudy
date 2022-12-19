当你们看到到这里时八成已经看过了评论区里第一位大神的代码了，很多对其代码的解释是消除长度差，事实确实是如此，但是解释有点太过于繁琐，大神消除长度差的方式不是“减去”而是“增加”。
我们寻常消除长度差的思想是，让长的那个链表减去比短的链表多出的那一部分，使两链表长度相同，然后开始遍历，而大神的代码是增加一段距离，使两个新的链表长度相等，然后从起点同时遍历，不管在什么位置，两链表剩余长度都是相同的如图：
![相交链表.png](https://pic.leetcode-cn.com/3da7113a09ba6de0a81dff4e63d142c5465138a8371ea66bda0113ed1bdb9ebf-%E7%9B%B8%E4%BA%A4%E9%93%BE%E8%A1%A8.png)
```
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{//假设A比B长
    if(headA==NULL||headB==NULL)return NULL;
    struct ListNode* pA=headA;
    struct ListNode* pB=headB;
    while(pA!=pB)//遍历两个链表
    {
        pA=pA==NULL?headB:pA->next;//构造链表D
        pB=pB==NULL?headA:pB->next;//构造链表C
        
    }
    return pA;
    

}`
```


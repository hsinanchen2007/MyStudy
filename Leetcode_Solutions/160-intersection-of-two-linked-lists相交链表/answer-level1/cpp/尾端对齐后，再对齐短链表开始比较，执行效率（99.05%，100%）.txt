注意到第一个示例,不是1，是从8开始，因此要比较地址；
![image.png](https://pic.leetcode-cn.com/ccf870f5ffe678d0233e97d7655608ea7f4cf34c5e9b9014afa6bde5312a3e82-image.png)

核心：长度不一致部分，不可能相同，类似于长短签在桌面对齐
1 计算链表长度，求插值，找出长链。由于是两数比较，差值可通过cnt++后再--计算。
2 对齐链表，逐个比较至尾

![image.png](https://pic.leetcode-cn.com/7aff06248e6676303623d09db5f5e062e8efc5cfa7ec6f03bd9f392937783e72-image.png)


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //核心：长度不一致部分，不可能相同，类似于长短签在桌面对齐
        //1 计算链表长度，求插值，找出长链。由于是两数比较，差值可通过cnt++后再--计算。
        //2 对齐链表，逐个比较至尾
        int cnt(0);
        ListNode *ptmp_a = headA;
        ListNode *ptmp_b = headB;
        while (ptmp_a != NULL)
        {
            cnt++;
            ptmp_a = ptmp_a->next;
        }

        while (ptmp_b != NULL)
        {
            cnt--;
            ptmp_b = ptmp_b->next;
        }

        ptmp_a = headA;
        ptmp_b = headB;

        if(0 <= cnt) while (cnt--) ptmp_a = ptmp_a->next;
        else while (cnt++) ptmp_b = ptmp_b->next; 
        
        while( ptmp_a != ptmp_b)
        {
            ptmp_a = ptmp_a->next;
            ptmp_b = ptmp_b->next;
        }
        return ptmp_a;            
    }
};
```
![image.png](https://pic.leetcode-cn.com/6756b94ac53f0728dd3ca2b1f55f855031de4b3b611cb5b9877d9b7b3dc6a1db-image.png)

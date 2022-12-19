1. 分别计算两两链表的长度
2. 较长的链表指针先走多的步数
3. 遍历查找相同链表
``` C++
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
        if(headA==NULL||headB==NULL)
            return NULL;
        ListNode* nodeA=headA;
        ListNode* nodeB=headB;
        //计算两链表的长度
        int lenA=0,lenB=0;
        while(nodeA)
        {
            lenA++;
            nodeA=nodeA->next;
        }
        while(nodeB)
        {
            lenB++;
            nodeB=nodeB->next;
        }
        //快指针先走较长链表多的步数        
        int first=(lenA>lenB)?(lenA-lenB):(lenB-lenA);
        if(lenA>=lenB)
        {
            for(int i=0;i<first;i++)
                headA=headA->next;
        }
        else
            for(int i=0;i<first;i++)
                headB=headB->next;
        //查找相同链表，两指针相遇结束循环
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
            
            
    }
};
```
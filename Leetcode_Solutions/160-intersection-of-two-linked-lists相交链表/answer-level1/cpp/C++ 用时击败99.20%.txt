需要遍历两次，每次都是O(m+n)的时间。

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

        ListNode *pA=headA;
        ListNode *pB=headB;
        if(!pA || !pB) //检验非空
            return NULL;

        //统计长度
        int lenA=0,lenB=0;
        while(pA->next){
            pA=pA->next;
            lenA++;
        }
        while(pB->next){
            pB=pB->next;
            lenB++;
        }
        //若结尾元素不一，必定不相交
        if(pA->val!=pB->val)
            return NULL;
        
        //先将头指针对齐
        pA=headA;
        pB=headB;
        if(lenA>lenB)
            for(int i=0;i<lenA-lenB;++i)
                pA=pA->next;
        else
            for(int i=0;i<lenB-lenA;++i)
                pB=pB->next;            

        //现在可以逐一检查元素是否一致
        while(pA){
            if(pA==pB)
                return pA;
            pA=pA->next;
            pB=pB->next;  
        }
        return NULL;
        
    }
};
```

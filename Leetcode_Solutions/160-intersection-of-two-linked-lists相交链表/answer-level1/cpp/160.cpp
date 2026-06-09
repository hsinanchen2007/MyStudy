```
//第一遍
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1,len2,dist;
        ListNode *p1=headA,*p2=headB;
        for(len1=0;p1;p1=p1->next,len1++);
        for(len2=0;p2;p2=p2->next,len2++);
        if(len1>len2)
        {
            dist=len1-len2;
            p1=headB;
            p2=headA;
        }
        else
        {
            dist=len2-len1;
            p1=headA;
            p2=headB;
        }
        while(dist--)
            p2=p2->next;
        while(p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
//第二遍；官方方法3
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        while(pA && pB)
        {
            pA = pA->next;
            pB = pB->next;
        }
        if(pA)
        {
            pB = headA;
            while(pA && pB)
            {
                pA = pA->next;
                pB = pB->next;
            }
            pA = headB;
            while(pA != pB)
            {
                pA = pA->next;
                pB = pB->next;
            }
            return pA;
        }
        else
        {
            pA = headB;
            while(pA && pB)
            {
                pA = pA->next;
                pB = pB->next;
            }
            pB = headA;
            while(pA != pB)
            {
                pA = pA->next;
                pB = pB->next;
            }
            return pA;
        }
    }
};
//第三遍；官方方法3 代码优化
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *pA = headA, *pB = headB;
        while(pA != pB)
        {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
    }
};
//第四遍；set 查找交点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> nset;
        while(headA)
        {
            nset.insert(headA);
            headA=headA->next;
        }
        while(headB)
        {
            if(nset.find(headB)!=nset.end())//if(nset.count(headB))
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};
```
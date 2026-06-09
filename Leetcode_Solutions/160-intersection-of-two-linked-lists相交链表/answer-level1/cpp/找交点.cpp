### 解题思路
if there is an intersection,then make A and B have the same beginner,recycle the list,find the location where A and B point to the same memory,that's the answer.

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
private:
    //headA和headB同起点
    ListNode* findInterSection(ListNode *headA, ListNode *headB) {
        while(headA->next&&headB->next) {
            if(headA==headB)
                break;
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* res;
        int lenA=1,lenB=1;
        //either A or B is null,then no intersection
        if(!headA||!headB) return NULL;

        ListNode *p=headA,*q=headB;
        //不相交返回null
        while(p->next){
            p = p->next;
            lenA++;
        }

        while(q->next){
            q = q->next;
            lenB++;
        }

        if(p!=q) return NULL;//不相交
        else{
            if(lenA>lenB){
                for(int i=0;i<lenA-lenB;i++) {
                    headA=headA->next;
                }
                res = findInterSection(headA,headB);
            }
            else{
                for(int i=0;i<lenB-lenA;i++) {
                    headB=headB->next;
                }
                res = findInterSection(headA,headB);
            }
        }
        return res;
    }

};
```
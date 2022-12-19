### 解题思路
相当于A,B两人绕着操场跑步，若以相同的速度，又走过相同的路程，必有相遇之时。


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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        if(headA==NULL || headB==NULL){
            return NULL;
        }

        while(p!=q){//未相遇时循环
            //在纸上画图更易理解。
//假设A距离交点更近，则会先到达交点，此时B未到达，那么A走到终点后折返到B的起点处，
//A，B继续走下去，A在B从起始到交点的路上相当于"补回"B之前比A多的路程；
//而若B走到终点后折返到A的起点处。此时二者走过的路程总和相同，达成同步，，
//之后便可步调一致，肩并肩相遇了。       
            p = (p==NULL) ?  headB : p->next;
            q = (q==NULL) ? headA : q->next;
            
        }
        return p;
    }
};
```
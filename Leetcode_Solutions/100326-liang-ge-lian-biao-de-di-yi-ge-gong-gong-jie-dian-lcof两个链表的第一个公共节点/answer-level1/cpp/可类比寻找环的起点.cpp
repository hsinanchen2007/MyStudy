### 解题思路
分三种情况讨论。
其中有公共交点的情况，可以转换为寻找一个环的起点。将headB尾部指向headB的首部即可。
这种方法是 用p、q两个指针，从headA出发，p速度为1，q速度为2。p、q相遇后，一个新的遍历指针从pHead出发，然后和p指针一起向后，p和新指针相遇的位置就是环的入口。
数学原理如下：
将环外部分结点个数记为a，环内结点个数记为b。
一倍速指针和二倍速指针相遇时，一倍速指针所走长度为n，二倍速指针所走长度为2n。假设相遇位置是环内第k个点。
则 n = a + xb + k; 2n = a + yb + k;
两个相减：n = (y-x)b;
则有 a + xb +k = (y-x)b → (y-2x)b  = a + k。
(y-2x)b  = a + k  注意等号左侧，是b的整数倍，我们当前位置是环内的第k个节点。也就是说，我们从当前节点往后走a步，那我们就一定能到环的开始位置。
如何控制走a步？这时候就需要从h位置个新的指针，和p节点一起往后走，相遇的位置，就是新节点刚刚走了a步，入环的位置。

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
        // 1、有null
        if(headA==NULL||headB==NULL) return NULL;
        // 2、两个链表无交点
        ListNode* p = headA;
        ListNode* q = headB;
        while(p->next!=NULL) p = p->next;
        while(q->next!=NULL) q = q->next;
        if(p!=q) return NULL;
        // 3、有交点
        // 以headA为开始部分
        p = headA; // 1倍速
        q = headA; // 2倍速
        do{
            // 1倍速
            if(p->next==NULL) p = headB;
            else p = p->next;
            
            // 2倍速
            if(q->next==NULL) q = headB;
            else q = q->next;
            if(q->next==NULL) q = headB;
            else q = q->next;
        }while(p!=q);
        q = headA;
        while(p!=q){
            q = q->next;
            if(p->next==NULL) p = headB;
            else p = p->next;
        }
        return p;
    }
};
```
## 408真题
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
        ListNode *pa=headA, *pb=headB;
        //遍历得到两个数组的长度
        int len_a=0, len_b=0;
        while(pa){
            pa=pa->next;
            len_a++;
        }
        while(pb){
            pb=pb->next;
            len_b++;
        }
        //长的那个先走|delta|步
        pa=headA;
        pb=headB;
        int delta = len_a - len_b;
        if(delta > 0){
            while(delta--) pa = pa->next;
        }
        else{
            delta = -delta;
            while(delta--) pb = pb->next;
        }
        //继续遍历，同时比较
        while(pa && pb && pa!=pb){
            pa = pa->next;
            pb = pb->next;
        }
        if(pa==pb) return pa;
        else return NULL;
    }
};
```
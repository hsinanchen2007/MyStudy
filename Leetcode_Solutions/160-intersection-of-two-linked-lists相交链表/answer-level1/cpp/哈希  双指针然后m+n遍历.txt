### 解题思路
**交叉**链表：
双指针然后m+n遍历 

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
                ListNode* pa=headA;
                ListNode* pb=headB;
                if(!headA||!headB)  return NULL;
                
                while(pa!=pb){
                    pa=pa->next;
                    pb=pb->next; 
                    if(pa==NULL&&pb!=NULL){
                        pa=headB;
                    }
                    if(pb==NULL&&pa!=NULL){ //这里的循环和后面的还是不一样的，
                                                //这里如果不判断一下pa就会死循环了
                        pb=headA;
                    }
                }
                return pa;

        // ListNode* pa=headA;
        // ListNode* pb=headB;
        // if(!headA||!headB)  return NULL;
        
        // while(pa!=pb){
        //    pa=(pa==NULL?headB:pa->next);
        //    pb=(pb==NULL?headA:pb->next);           
        // }
        // return pa;
    }
};
```
### 解题思路
快慢指针是最优解，哈希表的话,单个元素用set

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
    bool hasCycle(ListNode *head) {
        // if(head==NULL){
        //     return false;
        // }
        // ListNode* fast=head->next;
        // ListNode* slow=head;
        // while(fast&&slow){           
        //     if(slow->val == fast->val && slow->next == fast->next){
        //         return true;                
        //     }
        //     if(fast->next){
        //         fast=fast->next->next;
        //     }else fast=fast->next;
        //     slow=slow->next;
        // }
        // return false;  

      //没必要判断head->next， 因为后面的while中判断了，没有的话就直接最后return 了
            // ListNode* fast=head;
            // ListNode* slow=head;
            // while(fast&&fast->next){   //        只要快的不是NULL，那慢的一定不是
                
            //     fast=fast->next->next;
            //     slow=slow->next;
            //     if(slow== fast){ //这个判断也不用判断val了， 然后要放在指针错开之后才行，不然就直接输出了
            //         return true;                
            //     }
            // }
            // return false;   

        set<ListNode*> s;  
        while (head) {
            if (s.find(head) != s.end()) {
                return true;
            } else {
                s.insert(head);
                head = head->next;
            }
        }
        return false;




    }
};
```
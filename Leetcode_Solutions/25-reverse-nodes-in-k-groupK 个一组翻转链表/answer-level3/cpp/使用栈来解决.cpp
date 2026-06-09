### 解题思路
1.每次向前移动，便压入栈中
2.如果移动的个数与k相等，便重新更新链表。
3.每次移动个数与k相等时，要记录head

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
    ListNode* reverseKGroup(ListNode* head, int k){
        if(head==NULL || k<2){
            return head;
        }
        std::stack<int>_stack;
        int count=0;
        auto p=head;
        auto head_new=head;
        while(p!=NULL){
            _stack.push(p->val);
            ++count;
            p=p->next;
            if(count==k){
                while(!_stack.empty()){
                    head->val=_stack.top();
                    _stack.pop();
                    head=head->next;
                }
                count=0;
            }
        }

        return head_new;

    }
};
```
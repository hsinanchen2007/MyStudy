### 解题思路
寻找单链表，用的是hash

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
        map<ListNode*,int> nums;
        ListNode *p;
        p=head;
        while(p){
            if(nums.empty()||nums.find(p)==nums.end()){
                nums.insert(map<ListNode*,int>::value_type(p,1));
                p=p->next;
            }else break;
        }
        if(p) return true;
        else return false;
    }
};
```
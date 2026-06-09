### 解题思路
此处撰写解题思路

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
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL){
            return res;
        }
        if(head -> next == NULL){
            res.push_back(head ->  val);
            return res;
        }
        else{
            reversePrint(head -> next);
            res.push_back(head -> val);
            return res;
        }
    }
};
```
### 解题思路
1、遍历链表

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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        while(head!=NULL){
            ListNode* h=head;
            int cur=head->val;
            while(h!=NULL){
                if(h->next==NULL&&h->val<=cur) res.push_back(0);
                if(h->val>cur){
                    res.push_back(h->val);
                    break;
                }  
                h=h->next;       
            }
            head=head->next;
        }
        //if(head==NULL) res.push_back(0);
        return res;
    }
};
```
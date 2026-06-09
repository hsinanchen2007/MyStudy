### 解题思路
遍历两遍
第一遍将链表反向
第二遍顺序保存反向的链表各个节点的值

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
    vector<int> reversePrint(ListNode* head) {
    vector<int> ans;
        if(head==nullptr)
            return ans;
        if(head->next==nullptr){
            ans.push_back(head->val);
            return ans;
        }
    ListNode* node1=head->next;
    ListNode* node2=node1->next;
        head->next=nullptr;
         while(node2!=nullptr){
            node1->next=head;
            head=node1;
            node1=node2;
            if(node2!=nullptr)
                node2=node2->next;
        }
        // while(node2!=nullptr);
        node1->next=head;  
        //node1;
        while(node1!=nullptr){
            ans.push_back(node1->val);
            node1=node1->next;
        }
        return ans;
    }
};
```
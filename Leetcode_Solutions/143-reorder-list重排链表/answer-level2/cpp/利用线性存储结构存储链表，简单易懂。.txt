### 解题思路
此处撰写解题思路
利用vector将链表节点信息保存，然后再利用双索引技术，一次将节点取出相连。
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL 
            || head->next->next ==NULL) return;
        vector<ListNode*> node;
        while(head != NULL){
            node.push_back(head);
            head = head->next;
        }
        int l=0, r=node.size()-1;
        while(l<r){
            node[l]->next = node[r];
            node[r--]->next = node[++l];
        }
        node[l]->next = NULL;
        return;
    }
};
```
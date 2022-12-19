### 解题思路
直接遍历数组，若head->val == head->next->val,将head->next = head->next->next;（删掉相同的那一个结点）
若head->val ！= head->next->val，使head=head->next,(不相同则直接查看下一个结点)

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
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head){
            return NULL;
        }
        ListNode* res = head;//保存头节点，作为返回结果
        while(head && head->next){
            if(head->val != head->next->val){
                head = head->next;
            }
            else if(head->val == head->next->val){
                head->next = head->next->next;
            }
        }
        return res;
    }
};
```
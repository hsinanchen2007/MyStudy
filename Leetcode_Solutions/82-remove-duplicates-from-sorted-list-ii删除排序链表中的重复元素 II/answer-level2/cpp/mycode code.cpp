### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了 85.90%的用户
内存消耗 :6.8 MB, 在所有 C++ 提交中击败了 100.00% 的用户
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
        if (!head || !head->next)
            return head;

        bool isDup = false;
        ListNode* cur = head;
        ListNode* newHead = head;
        ListNode* father = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
                isDup = true;
            } else {
                if (isDup){
                    // 上一个节点有问题
                    if (cur){
                        if (!cur->next){
                            father->next = NULL;
                            break;
                        }
                        
                        if (cur == newHead){
                            cur = cur->next;
                            father = cur;
                            newHead = cur;
                        } else {
                            cur = cur->next;
                            father->next = cur;
                        }
                    }
                    isDup = false;
                } else {
                    father = cur;
                    cur = cur->next;
                }
               
            }
        }

        if (cur && !cur->next && isDup){
            if (cur == newHead){
                return NULL;
            }

            father->next = NULL;
        }

        return newHead;
    }
};
```
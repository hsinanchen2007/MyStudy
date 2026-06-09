### 解题思路
1. 如果k < 链表长度，步进到末尾的倒数k节点，进行节点转化，O(N).
2. 如果k > 链表长度，经过1步骤后，缩短k = k % len, 重复1步骤。

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
    ListNode* rotateRight(ListNode* head, int k) {        
        ListNode *targetNode = NULL;
        ListNode *lastNode = NULL;
        while(targetNode == NULL && head != NULL && k > 0) {
            int len = 0;
            ListNode *node = head;
            while (node) {
                if (len >= k) {
                    targetNode = targetNode == NULL ? head : targetNode->next;
                }
                if (node->next == NULL) {
                    lastNode = node;
                }

                node = node->next;
                len++;
            }
            k = k % len;
        }

        if (targetNode && targetNode->next) {
            lastNode->next = head;
            head = targetNode->next;
            targetNode->next = NULL;
        }

        return head;
    }
};
```
### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/468991a764f41c276727ca8cb79b1d77b6eaccbfcadc04471f8016dcc86ec552-image.png)

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
        if (!head) {
            return NULL;
        }
        ListNode pHead = ListNode(0);
        pHead.next = head;
        ListNode* ptrF = head->next;
        ListNode* ptrS = &pHead;
        while (ptrF) {
            if (ptrF->val == ptrS->next->val) {
                while (ptrF && ptrF->val == ptrS->next->val) {
                    ptrF = ptrF->next;
                }
                ptrS->next = ptrF;
            } else{
                ptrS = ptrS->next;
            }
            // cout << "ptrS: " << ptrS->val;
            
            if (ptrF) {
                // cout << "ptrF:" << ptrF->val << endl;;
                ptrF = ptrF->next;
            }
        }
        return pHead.next;
    }
};
```
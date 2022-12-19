### 解题思路
1.将链表变为vector，方便随机操作
2.双指针，left和right，两边向中间移动，如果都相等则是回文，如果有一个不相等，则不是回文

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
    bool JudgePalindrome(int left, int right, vector<ListNode *> &nodes)
    {
        while (left < right) {
            if (nodes[left]->val == nodes[right]->val) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr) {
            return true;
        }

        vector<ListNode *> nodes;
        ListNode *node = head;
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }
        int left = 0;
        int right = nodes.size() - 1;
        bool result = JudgePalindrome(left, right, nodes);

        return result;
    }
};
```
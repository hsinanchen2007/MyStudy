### 解题思路
使用一个数组记住数字是否出现过

![image.png](https://pic.leetcode-cn.com/8983e5827238c19babede09bb282508f3b249e4b1eecbac9eabec08e86cac031-image.png)

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        int hash[20000] = {0};
        ListNode* node = head;
        if(!head)   return head;
        if(node->next == NULL) return head;
        hash[node->val]++;
        while(node->next->next)
        {
            if(hash[node->next->val] == 0)
            {
                hash[node->next->val]++;
                node = node->next;
            }

            else{
                node->next = node->next->next;
            }
        }

        if(hash[node->next->val] == 1)
            node->next = NULL;

        return head;
    }
};
```
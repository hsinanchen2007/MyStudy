### 解题思路
双指针   （关注微信公众号'码农黑板报' 获取更多题解）
![image.png](https://pic.leetcode-cn.com/74f98ccc5b73bc2e3922e1770ab0d1e709f47bdd42235cd2792257efd920376d-image.png)


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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = NULL;
        
        while (head) {
            cur = head;
            head = head->next;
            cur->next = pre;
            pre = cur;
        }
        return cur;
    }
};
```
### 解题思路
双指针法，但很奇怪，我和另一个哥们[@Taraxacumyj](/u/taraxacumyj/) 写的思路都差不多，而且我还比他省略了两步：判断head是否为空，删除自己添加的头结点，为啥他能达到100%，而我才86.66%？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentry = new ListNode(0);
        sentry->next = head;
        ListNode* left = sentry;
        ListNode* right = sentry;

        for (int i = 0; i < n; ++ i ) {
            right = right->next;
        }

        while(right->next) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return sentry->next;
    }
};


```

![微信截图_20200406212813.png](https://pic.leetcode-cn.com/ed162e9f91448d65edae6b035c9bfe26d92434e770fc7f20e82a139b5abfc341-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200406212813.png)

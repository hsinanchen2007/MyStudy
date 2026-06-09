思路如下图：
![反转链表.jpg](https://pic.leetcode-cn.com/b9c03211df72e3cef64ae0c2e1ec546f23078dfb135259aaabc9aeb4628092a7-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.jpg)
```
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
        ListNode *left = NULL, *right = head;
        while(right)
        {
            auto mid = right->next;  // auto声明变量的类型由编译器在编译时期自动推导而得。
            right->next = left;
            left = right;
            right = mid;
        }
        return left;
    }
};
```


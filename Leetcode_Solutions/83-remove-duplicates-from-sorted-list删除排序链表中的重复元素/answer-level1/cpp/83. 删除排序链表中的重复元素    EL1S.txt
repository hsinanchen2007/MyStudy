每个重复的元素只留下一个，通过修改next指针的位置来实现

![image.png](https://pic.leetcode-cn.com/f2b36b025bc285ad6ec92a60a4bccbc5996f0d83a0c4ce71397bc87f3de0c8ea-image.png)
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto left = head;
        while(left)
        {
            auto right = left->next;
            while(right && left->val == right->val)
            {
                right = right->next;
            }
            left->next = right;
            left = left->next;
        }
        return dummy->next;
    }
};
```





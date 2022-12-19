![微信图片_20200325232733.png](https://pic.leetcode-cn.com/19f279e5bfed883d35fe12b8e154c5469944425ac6ddf3e8889921273eb5f1cf-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200325232733.png)

```
创建两个头结点，形成双链表，最后合并，时间复杂度O(N),空间复杂O(1)
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* big = new ListNode(0);
        ListNode* small = new ListNode(0);
        ListNode* small_head = small;
        ListNode* big_head = big;
        ListNode* p = head;
        while(p)
        {
            if(p->val < x)
            {
                small->next = p;
                small = small->next;
            }
            else
            {
                big->next = p;
                big = big->next;
            }
            p = p->next;
        }
        big->next = NULL;
        small->next = big_head->next;
        return small_head->next;
    }
};
```
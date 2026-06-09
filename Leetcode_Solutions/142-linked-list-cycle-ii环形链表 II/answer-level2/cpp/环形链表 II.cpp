双指针法求解，那么如何找到相交点的位置呢，如下：

![微信图片_20190613201852.jpg](https://pic.leetcode-cn.com/23900823a36335da90a79892ad2a4cc57c4b90a9cea6340c098e36baf15dd0b7-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190613201852.jpg)

实现如下：

```C++ []
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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
```
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
    ListNode* middleNode(ListNode* head) {
        //法一，快慢指针，快指针到头，慢指针正好到中间
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

        //法二，先遍历一遍得到元素总数，再遍历一遍返回中间元素
        // int cnt = 0;
        // ListNode* p = head;
        // while(p != NULL)
        // {
        //     cnt++;
        //     p = p->next;
        // }
        // int i=0;
        // cnt /= 2;
        // ListNode* q = head;
        // while(q != NULL)
        // {
        //     if(i == cnt) return q;
        //     q = q->next;
        //     i++;
        // }
        // return NULL;

        //法三，先遍历一遍存在数组里，再遍历一次同时判断是否与中间元素值相等（但是错了，因为测试数据里会有重复的值），可以解决但是没必要qaq
        // vector<int> num;
        // ListNode* p = head;
        // while(p != NULL)
        // {
        //     num.push_back(p->val);
        //     p = p->next;
        // }
        // ListNode* q = head;
        // while(q != NULL)
        // {
        //     if(q->val == num[num.size()/2])
        //         return q;
        //     q = q->next;
        // }
        // return NULL;
    }
};
```
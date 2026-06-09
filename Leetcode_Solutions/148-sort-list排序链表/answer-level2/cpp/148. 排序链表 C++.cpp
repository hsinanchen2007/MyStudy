### 解题思路
1、借助数组，使用数组快速排序

2、对链表归并排序


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


bool compare(ListNode* left, ListNode* right)
{
    return left->val < right->val;
}


class Solution {
public:

    //1
    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        //借助数组
        vector<ListNode*> v;
        while (head)
        {
            v.push_back(head);
            head = head->next;
        }

        //对指针数组按值进行排序
        sort(v.begin(), v.end(), compare);

        //重新串连数组
        for (int i = 0; i < v.size() - 1; ++i)
        {
            v.at(i)->next = v.at(i + 1);
        }
        v.back()->next = nullptr;

        return v.front();
    }


    //2、归并排序
    ListNode* median(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if (head1 == nullptr)
            return head2;
        else if (head2 == nullptr)
            return head1;

        ListNode* cur_1 = head1;
        ListNode* cur_2 = head2;
        ListNode* cur = nullptr;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (cur_1 && cur_2)
        {
            if (cur_1->val < cur_2->val)
            {
                cur = cur_1;
                cur_1 = cur_1->next;
            }
            else
            {
                cur = cur_2;
                cur_2 = cur_2->next;
            }
            
            if (head == nullptr)
            {
                head = cur;
                tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }
        }

        if (cur_1)
        {
            tail->next = cur_1;
        }
        else if (cur_2)
        {
            tail->next = cur_2;
        }

        return head;
    }


    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        //找中点, 拆成两半
        ListNode* mid = median(head);

        ListNode* head2 = mid->next;

        mid->next = nullptr;

        //对左半部分链表归并排序
        head = sortList(head); //head到mid

        //对右半部分链表归并排序
        head2 = sortList(head2); //mid->next到链表尾

        //合并两部分有序链表
        return merge(head, head2);
    }

};
```
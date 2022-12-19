### 解题思路
此处撰写解题思路

封装两个函数
reverse负责将传入的链表翻转
kReverse从传入的链表头部中，划出长度为k的区间，调用reverse将区间翻转

最后实现接口reverseKGroup，调用kReverse翻转链表，直到将全部链表处理完毕
reverseKGroup也可以用递归实现

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *new_head = kReverse(head, k);
        
        // 第一个区间长度不足k，直接返回，无需翻转
        if (new_head == head)
            return new_head;

        ListNode *new_group_head = NULL;
        ListNode *last_group_tail = head;
        head = last_group_tail->next;

        // 所有节点都已经翻转，或者最后一个区间长度不足k无需翻转
        while (head != NULL
            and new_group_head != head) {

            // 将区间翻转，head由头部变成区间尾部
            new_group_head = kReverse(head, k);
            
            // 将上一个区间，连接上翻转后的区间头部
            last_group_tail->next = new_group_head;
            
            // 继续处理下一个区间
            last_group_tail = head;
            head = last_group_tail->next;
        }
        
        return new_head;
    }

private:
    ListNode* kReverse(ListNode* head, int k) {
        ListNode *tail = head;
        for (int i = 0; i<k-1 and tail!=NULL; i++)
            tail = tail->next;
        if (tail == NULL)
            return head;
        
        return reverse(head, tail);
    }

    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = head;
        ListNode *cur = head->next;

        if (cur == NULL)
            return head;

        while (pre != tail) {
            head->next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = head->next;
        }

        return tail;
    }
};
```
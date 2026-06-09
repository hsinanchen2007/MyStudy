### 解题思路
此处撰写解题思路
1. 计算长短链, l1一直为长, l2为短.
2. 递归从后往前计算, 注意判断位数是否对齐.
3. 最后根据余数判断是否需要增加链表的长度.
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
    int _len;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length_1 = get_length(l1);
        int length_2 = get_length(l2);
        // l1长链, l2短链
        if (length_2 > length_1) {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
            swap(length_1, length_2);
        }
        this->_len = length_1 - length_2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        // 递归
        int mod = func(p1, p2, 0);
        while (mod > 0) {
            ListNode* head = new ListNode(mod % 10);
            mod /= 10;
            head->next = l1;
            l1 = head;
        }
        return l1;
    }
    int func(ListNode* p1, ListNode* p2, int step) {
        int temp;
        if (step < _len) {
            temp = p1->val + func(p1->next, p2, step + 1);
        }
        else {
            if (!p1 and !p2) return 0;
            temp = p1->val + p2->val + func(p1->next, p2->next, step + 1);
        }
        p1->val = temp % 10;
        return temp / 10;
    }
    int get_length(ListNode* l) {
        ListNode* p = l;
        int length = 0;
        while (p) {
            p = p->next;
            ++length;
        }
        return length;
    }
};
```
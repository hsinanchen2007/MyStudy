### 解题思路


### 代码

```cpp

class Solution {
public:
    //两个非空链表  返回一个新的链表 创建新结点
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* cur_1 = l1;
        ListNode* cur_2 = l2;

        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;

        int carry = 0; //低位是否有进位

        while (cur_1 || cur_2)
        {
            //创建结点
            int x = cur_1 ? cur_1->val : 0;
            int y = cur_2 ? cur_2->val : 0;
            int val = x + y + carry;
            carry = val / 10;
            ListNode* node = new ListNode(val % 10);

            //插入新链表
            if (new_head == nullptr)
            {
                new_head = node;
                new_tail = node;
            }
            else //尾插
            {
                new_tail->next = node;
                new_tail = new_tail->next;
            }

            if (cur_1)
            {
                cur_1 = cur_1->next;
            }

            if (cur_2)
            {
                cur_2 = cur_2->next;
            }
        }

        if (carry == 1) //最高位进位
        {
            new_tail->next = new ListNode(1);
            new_tail = new_tail->next;
        }

        return new_head;
    }
};
```
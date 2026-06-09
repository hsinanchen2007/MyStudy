### 解题思路
方法1: 反转链表

进阶：方法2、使用栈替代反转链表

### 代码

```cpp

class Solution {
public:
    //方法1
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //对两个链表进行反转
        l1 = list_reverse(l1);
        l2 = list_reverse(l2);

        //使用 题目2. 两数相加 函数
        ListNode* head = addTwoNumbers_inverse(l1, l2);

        //再将l1、l2反转回去
        l1 = list_reverse(l1);
        l2 = list_reverse(l2);

        //将结果反转
        return list_reverse(head);
    }

    ListNode* list_reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    //题目2. 两数相加 函数
    ListNode* addTwoNumbers_inverse(ListNode* l1, ListNode* l2) {

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


    //2、使用栈 并 逆序构建结果链表
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> stack1;
        while (l1)
        {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        stack<int> stack2;
        while (l2)
        {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* prev = nullptr;
        ListNode* node = nullptr;

        int carry = 0;

        while (!stack1.empty() || !stack2.empty())
        {
            int x = stack1.empty() ? 0 : stack1.top();
            int y = stack2.empty() ? 0 : stack2.top();

            if (!stack1.empty())
            {
                stack1.pop();
            }

            if (!stack2.empty())
            {
                stack2.pop();
            }

            int val = x + y + carry;
            carry = val / 10;

            prev = node;
            node = new ListNode(val % 10);
            node->next = prev;
        }

        if (carry == 1)
        {
            prev = node;
            node = new ListNode(1);
            node->next = prev;
        }

        return node;
    }
};
```
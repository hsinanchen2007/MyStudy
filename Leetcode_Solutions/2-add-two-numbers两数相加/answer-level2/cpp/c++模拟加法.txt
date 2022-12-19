### 题目描述
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
```c++
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```
### 算法

思路：模拟人工加法
    1.从低位到高位逐位相加，如果和大于等于10，就保留这个数的余数，并向前进1
    2.如果最高位后面还有进位，就在前面添个1

### c++代码
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int t = 0;            
        while(l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            t = n1 + n2 + t;                //表示两个数的和加上进位
            cur -> next = new ListNode(t % 10) ;
            t /= 10;
            cur = res->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(t) cur->next = new ListNode(1);  // 进位
        return res->next;
    }
};
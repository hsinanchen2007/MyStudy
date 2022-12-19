### 解题思路
图省事儿就用递归了呗？
遵循末位相加、大于十再进位的基本原则，我把进的一位直接加到了第一个加数的末位（指用于接下来递归的加数l1,l1/l2本来的末尾数字在加法之后即“扔掉”）。
这样做的坏处是会导致l1运行完之后每个node都有可能被改变，如果后续再有其他操作的话就必须要在一开始复制出一条链表（而不能用双指针）

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val+l2->val<10)
        {
            ListNode* t =new ListNode(l1->val+l2->val);
            t->next=addTwoNumbers(l1->next,l2->next);
            return t;
        }
        ListNode* t =new ListNode(l1->val+l2->val-10);
        l1=addTwoNumbers(l1->next,new ListNode(1));
        l2=l2->next;
        t->next= addTwoNumbers(l1,l2);
        return t;
    }
};
```
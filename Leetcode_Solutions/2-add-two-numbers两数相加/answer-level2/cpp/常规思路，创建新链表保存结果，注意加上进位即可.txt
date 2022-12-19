### 解题思路
创建一个新链表l3用来存放结果，用一个变量temp表示是否有进位，然后用cur1,cur2,cur3来循环遍历l1,l2,l3。循环结束的条件是cur1为空并且cur2为空并且temp为0。

当cur1和cur2中有一个为空时，表明这个链表已遍历完，因此要在后方继续补0，与另一个链表继续相加。

当cur1和cur2都为空，但temp不为0时，表明两个链表都已遍历完，但是还有进位，因此继续在两个链表后方补0，与进位相加。

当cur1和cur2都为空，且temp为0时，表明两个链表都已遍历完，且进位已经加上，退出循环，输出结果。

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
        ListNode *l3 = new ListNode(-1) , *cur1 = l1, *cur2 = l2, *cur3 = l3;
        int temp = 0;
        while(cur1 != NULL || cur2 != NULL || temp != 0){
            if(cur1 == NULL)                        //l1已遍历完，在后方补0节点
                cur1 = new ListNode(0);
            if(cur2 == NULL)
                cur2 = new ListNode(0);             //l2已遍历完，在后方补0节点
            cur3->next = new ListNode((cur1->val + cur2->val + temp) % 10);
            if(cur1->val + cur2->val + temp < 10)   //判断是否有进位
                temp = 0;
            else
                temp = 1;
            cur1 = cur1->next;
            cur2 = cur2->next;
            cur3 = cur3->next;
        }
        return l3->next;
    }
};
```
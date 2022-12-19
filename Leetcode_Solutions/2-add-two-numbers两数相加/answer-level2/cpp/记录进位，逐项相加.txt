### 解题思路
按位相加，记录进位flag（初始化为0）;
相加时加上flag一起加;
若还有剩余则单独处理剩余链表;
若最终flag仍为1，则末尾加1.

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
        int sum = 0;
        int flag = 0;         //初始化flag为0
        ListNode* temp = new ListNode(0);
        ListNode* p = temp;
        while(l1&&l2){
            sum = l1->val + l2->val + flag;   //计算两数之和
            flag = sum >= 10 ? 1 : 0;         //确定flag的值（个数相加不会大于20，故flag为1或0）
            l1 = l1->next;
            l2 = l2->next;
            ListNode* newnode = new ListNode(sum%10);  //将新结点插入链表
            p->next = newnode;
            p = p->next;
        }
        //单独处理l1剩余部分
        while(l1){
            sum = l1->val + flag;
            flag = sum >= 10 ? 1 : 0;
            ListNode* newnode = new ListNode(sum%10);
            p->next = newnode;
            p = p->next;
            l1 = l1->next;
        }
        //单独处理l2剩余部分
        while(l2){
            sum = l2->val + flag;
            flag = sum >= 10 ? 1 : 0;
            ListNode* newnode = new ListNode(sum%10);
            p->next = newnode;
            p = p->next;
            l2 = l2->next;
        }
        //最终flag为1则需要进位一个单独的“1”
        if(flag){
            ListNode* newnode = new ListNode(1);
            p->next = newnode;
            p = p->next;
        }
        return temp->next;
    }
};
```
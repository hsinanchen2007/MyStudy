```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0); // 创建结果链表头结点
        ListNode *m = head;//移动结点
        int ov = 0;//初始化进位
        int a = 0, b = 0;// 定义两个加数
        while (l1 || l2) // 两链表中其中一个有值
        {
            l1 ? a = l1->val: a = 0; 
            l2 ? b = l2->val: b = 0;//初始化第一个、第二个加数，考虑l1、l2为空的情况
            m->next = new ListNode((a + b + ov) % 10);// 创建新结点
            ov = (a + b + ov) / 10;//更新进位
            m = m->next;//向后移动结果链表
            l1 ? l1 = l1->next : l1 = nullptr;
            l2 ? l2 = l2->next : l2 = nullptr;//向后移动加数链表
        }
        if (ov == 1)//考虑最后一位进位的情况
            m->next = new ListNode(1);
        
        ListNode *p = head;
        head = head->next;
        delete p;//删除头结点
        return head;
       }
```
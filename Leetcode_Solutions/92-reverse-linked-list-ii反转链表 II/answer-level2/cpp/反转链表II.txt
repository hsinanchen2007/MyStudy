思路：
第一步：找到要反转的链表段的头节点
第二步：设置反转后的链表尾
第三步：反转需要反转的链表段
第四步：将反转后的链表尾与反转段的后一个节点连接
第五步：判断链表是否从第一个节点开始反转，然后返回反转后的链表头节点
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        //计算需要逆置的节点个数
        int change_len = n - m + 1;
        //初始化开始逆置的节点的前驱
        ListNode * pre_head = NULL;
        //最终转换后的链表头节点，非特殊情况即为head
        ListNode * result = head;
        //将head向前移动m-1个位置，--m（--m是先将变量值减1，再取变量m）和m--（m--是先取变量m，再将变量m值减1）有区别
        while (head && --m)
        {
            pre_head = head;
            head = head -> next;
        }
        //逆置后的链表尾
        ListNode * modify_list_tail = head;
        ListNode * new_head = NULL;
        //逆置change_len个节点
        while(head && change_len)
        {
            ListNode * next = head -> next;
            head -> next = new_head;
            new_head = head;
            head = next;
            change_len--;
        }
        //连接逆置后的链表尾与逆置段的后一个节点
        modify_list_tail -> next = head;
        if (pre_head)         //如果pre_head不为空，说明不是从第一个节点开始逆置的
        {
            pre_head -> next = new_head;
        }
        else
        {
            result = new_head;
        }
        return result;
    }
};```
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        //计算需要逆置的节点个数
        int change_len = n - m + 1;
        //初始化开始逆置的节点的前驱
        ListNode * pre_head = NULL;
        //最终转换后的链表头节点，非特殊情况即为head
        ListNode * result = head;
        //将head向前移动m-1个位置，--m（--m是先将变量值减1，再取变量m）和m--（m--是先取变量m，再将变量m值减1）有区别
        while (head && --m)
        {
            pre_head = head;
            head = head -> next;
        }
        //逆置后的链表尾
        ListNode * modify_list_tail = head;
        ListNode * new_head = NULL;
        //逆置change_len个节点
        while(head && change_len)
        {
            ListNode * next = head -> next;
            head -> next = new_head;
            new_head = head;
            head = next;
            change_len--;
        }
        //连接逆置后的链表尾与逆置段的后一个节点
        modify_list_tail -> next = head;
        if (pre_head)         //如果pre_head不为空，说明不是从第一个节点开始逆置的
        {
            pre_head -> next = new_head;
        }
        else
        {
            result = new_head;
        }
        return result;
    }
};
```

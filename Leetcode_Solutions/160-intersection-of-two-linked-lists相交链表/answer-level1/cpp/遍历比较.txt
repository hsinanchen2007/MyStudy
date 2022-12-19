思路：
第一步：定义一个计算链表长度的函数，定义一个移动较长链表头指针的函数；
第二步：计算两个链表的长度，并将较长的链表的头节点移动
第三步：比较链表A和链表B的每一个结点，看是否有相等的
//定义一个计算链表长度的函数
int get_list_length(ListNode * head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head -> next;
    }
    return len;
}
//将较长链表的指针向前移动到多出结点个数后面的位置
ListNode * forward_long_list(int long_len, int short_len, ListNode * head)
{
    int delta = long_len - short_len;
    while(head && delta)
    {
        head = head -> next;
        delta--;
    }
    return head;
}
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int lenA = get_list_length(headA);
        int lenB = get_list_length(headB);
        if (lenA > lenB)
        {
            headA = forward_long_list (lenA, lenB, headA);
        }
        else
        {
            headB = forward_long_list(lenB, lenA, headB);
        }
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};
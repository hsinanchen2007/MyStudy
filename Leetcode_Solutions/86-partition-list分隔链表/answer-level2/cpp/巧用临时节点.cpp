//巧用临时节点
思路：
首先声明两个临时结点（为什么不是指向结点的指针，而是结点？），然后创建两个指向这两个结点的指针。第三步遍历链表，比较结点处val（如何读取结点val）与x，如果结点val小于x，则连接到less_node后面，如果结点val大于等于x，则连接到more_node后面。遍历完成后让最后一个结点指针指向NULL，然后连接两个新链表属于原链表的部分，然后返回指向新链表链表头的指针。
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        //声明两个临时变量。这两个的作用是不变的头，便于后面连接两个分开的链表以及返回链表头
        ListNode less_node(0);
        ListNode more_node(0);
        //创建两个指向这两个结点的指针
        ListNode * less_head = &less_node;
        ListNode * more_head = &more_node;
        //遍历该链表，并将小于x的结点连接到小结点后面，大于等于x的结点连接到大结点后面
        while(head)
        {
            if (head -> val < x)
            {
                less_head -> next = head;
                less_head = head;
            }
            else
            {
                more_head -> next = head;
                more_head = head;
            }
            head = head -> next;
        }
        more_head -> next = NULL;
        less_head -> next = more_node.next;
        return less_node.next;
    }
};
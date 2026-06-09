
时间复杂度 n/2+n/2+n+n/2=2.5n，也就是o(n)了
思路：
2. 1. 首先双指针找到链表中间和右链表的首结点，将一个链表分为左右两个链表。
    若结点个数为奇数(1->2->3)，中间结点为2，右链表的首结点为 3。
    若结点个数为奇数(1->2->3->4)，中间结点为2，右链表的首结点为 3。
2. 翻转右链表
3. 判断左右链表是否相同，相同也就是回文
4. 还原右链表，并把左右链表连接。
```
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* p1=head,*p2=head;
        while(p2->next!=NULL&&p2->next->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next->next;
        }//结束后 p1 为尾结点 p1->next为 链表右面第一个 结点

        //将 单链表 分成两个单链表
        ListNode* rigP=p1->next; //记录 右链表的第一个结点
        p1->next=NULL;

        //反转右链表
        ListNode* rigPhead=NULL;
        while(rigP!=NULL)
        {
            ListNode* tmp=rigP->next;
            rigP->next=rigPhead;
            rigPhead=rigP;
            rigP=tmp;
        }// 结束后 rigPhead 为新链表首结点 rigP为最右空结点

        bool res=true; //初始化返回变量

        // 进行比较
        while(head!=NULL&&rigPhead!=NULL)
        {
            if(head->val!=rigPhead->val)
            {
                res=false;
                break;
            }
            head=head->next;
            rigPhead=rigPhead->next;
        }

        //再将右面链表复原  rigPhead 为右链表首结点 rigP 为最右空结点
        while(rigPhead!=NULL)
        {
            ListNode* tmp=rigPhead->next;
            rigPhead->next=rigP;
            rigP=rigPhead;
            rigPhead=tmp;
        }// 结束后  rigP 为链表首结点

        //将左链表尾连接到右链表首
        p1->next=rigP;

        return res;
    }
};
```

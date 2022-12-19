要点有3个：
1、创建一个头节点，方便链表的操作
2、注意进位的操作，要保存进位
3、当遍历完毕，进位不为0，记得添加一个val为1的节点
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);//头节点，方便操作
        ListNode *current;
        current=head;
        int num;
        int jinwei=0;//进位
        int shuzhi=0;//存进节点的数值
        while(l1!=NULL || l2!=NULL)
        {
            num=0;
            if(l1!=NULL)
            {
                num+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                num+=l2->val;
                l2=l2->next;
            }
            num+=jinwei;
            jinwei=num/10;
            shuzhi=num%10;
            /*新的节点*/
            ListNode *newNode=new ListNode(shuzhi);
            current->next=newNode;
            current=current->next;
        }

         /*进位不为0，仍要创建新的节点*/
        if(jinwei!=0)
        {
            ListNode *newNode=new ListNode(1);
            current->next=newNode;
            current=current->next;
        }
        return head->next;
    }
};
```

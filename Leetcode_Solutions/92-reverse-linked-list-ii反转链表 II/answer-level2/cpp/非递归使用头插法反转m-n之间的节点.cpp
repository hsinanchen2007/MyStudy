```c++
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
    //注：ans和root都是带头结点的链表
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)return head;
        auto root=new ListNode(0);//要反转的m-n节点的头节点
        auto ans=new ListNode(0);//最后答案的头节点
        auto f=ans;//f为ans的工作指针
        ListNode* p=NULL;//p记录头插法中的头节点后的节点
        ListNode* first=NULL;//第一个要反转的节点
        int i=1;
        while(head){
            if(i>=m&&i<=n){
                if(i==m)first=head;//记录第一个反转的节点
                auto q=head;//使用头插法反转m-n的所有节点,q是要插入头节点后的节点
                head=head->next;
                root->next=q;
                q->next=p;
                p=q;
            }else if(i>n){
                first->next=head;//将n后面的节点接在第一个反转的节点后面
                first = first->next;
                head=head->next;
            }
            else{
                f->next=head;//前面的节点不动
                f=f->next;
                head=head->next;
            }
            i++;
        }
        f->next=root->next;//将反转后的头节点的next节点接在m之前的节点后面
        return ans->next;
    }
};
```
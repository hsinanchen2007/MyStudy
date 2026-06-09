1:声明一个指针p，用p遍历链表找到第k+1位，若当前链表长度短于k则返回当前链表。
2:翻转前k个节点，翻转后head节点对应链尾。此时将链尾与p连接，就完成了一次翻转。
3:递归此过程，直至完成全部翻转。
![WechatIMG25154.png](https://pic.leetcode-cn.com/08b7c56fd38372cf59cf26e8389d9769c8b1ecf5c5ee6fe30c2d850022a51cde-WechatIMG25154.png)
```
class Solution {
public:
    ListNode* reverse(ListNode* head,int k){
        if(k==1)return head;
        ListNode*cur=reverse(head->next,k-1);
        head->next->next=head;
        head->next=NULL;
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* p=head;
        while(p&&count<k){
            count++;
            p=p->next;
        }
        if(count<k)return head;
        ListNode*newHead=reverse(head,k);
        head->next=reverseKGroup(p,k);
        return newHead;
    }
};
```

![QQ图片20190829105338.png](https://pic.leetcode-cn.com/c31651cb2be6090f3eb2879705e295615b30ef6e7c892f9297c110b8e09f1e4d-QQ%E5%9B%BE%E7%89%8720190829105338.png)
迭代法转置链表，也不难，看注释就行
- 
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        {
            return head;//空的就直接返回
        }
        ListNode*now = head;//记录当前节点
        ListNode*next = now->next;//记录当前节点的下一个节点
        ListNode *n = next;//最后返回的头节点
        if(next==NULL)//只有一个节点也直接返回
        {
            return head;
        }
        while(1)
        {
            now->next = next->next;//当前节点指向下一个的下一个
            next->next=now;//下一个节点指向当前节点，这就实现了一次两两互换
            ListNode*pre = now;//记录当前的pre节点，后面要用
             
            if(now->next!=NULL)//如果后面还有节点
            {
                //now 和next分别后移两位
                now = now->next;
                next = now->next;
               
            }
            else//没有就break，这是针对节点数为偶数的情况
            {
                break;
            }
            if(next!=NULL)//如果next不是空，即节点数为偶数，此时next对应的为 2，4,6,8等等
            pre->next = next;
            else//节点数为奇数,则必然最后一个节点的next为空
            {
                break;
            }
        }
        return n;
    }
};
```

### 解题思路
环形链表

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
    //将链表每个节点向右移动k个位置  k>0
    ListNode* rotateRight(ListNode* head, int k) {
        //首先设置成一个环形链表，然后选择起始节点，顺序遍历一次整个链表，接着把最后一个节点的next设置成nullptr即可
        if(head==nullptr||head->next==nullptr||k==0) return head;
        int n=0;
        ListNode* pNode = head;
        while(pNode->next!=nullptr)
        {
            pNode = pNode->next;
            n++;
        }
        n++;
        //得到了链表长度
        int x = k%n;
        if(x==0) return head;
        pNode->next = head;
        //制作成了环形链表，接着寻找头节点
        x = n-x;
        ListNode* newhead = head;
        while(x--)
        {
            newhead = newhead->next;
        }
        //当前就是新的根节点
        ListNode* pnewtail = newhead;
        while(--n)
        {
            pnewtail = pnewtail->next;
        }
        pnewtail->next = nullptr;
        return newhead;
    }
};
```
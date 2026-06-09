### 解题思路
遍历链表，用尾插法生成两个链表，分别存放小于目标值x的节点和大于等于x的节点，然后将两个链表连接起来。
![image.png](https://pic.leetcode-cn.com/8d6cca11115d83b3b280807bdcf5bf632e842be9e2c0d9bb894d3acd3f81c1d6-image.png)

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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode *Lhead=new ListNode(0),*Hhead=new ListNode(0);
        ListNode *l=Lhead,*h=Hhead;
        while(head)
        {
            if(head->val<x)
            {
                l->next = head;
                head = head->next;
                l = l->next;
                l->next = nullptr;
            }
            else 
            {
                h->next = head;
                head = head->next;
                h = h->next;
                h->next = nullptr;
            }
        }
        l->next=Hhead->next;
        return Lhead->next;
    }
};
```
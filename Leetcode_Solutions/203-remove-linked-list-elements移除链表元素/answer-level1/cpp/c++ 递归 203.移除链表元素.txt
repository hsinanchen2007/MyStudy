### 解题思路
把链表看成 一个头结点连接一个链表：
比如 1->2->3->4->3->NUL    删除 3
把他看成： 1 连接2->3->4->3->NUL这个链表
对2->3->4->3->NUL来说看成：2 连接3->4->3->NUL这个链表
对3->4->3->NUL来说看成：3 连接4->3->NUL这个链表

以此类推：直到 一个空表 就是递归的基本解
那么我们如果是基本解就返回；
不是就用一个指针指向我们已经删除val这个元素剩下的链表
如果当前head的val是目标val，删除当前head也就是返回这个指针，否则 将当前已经删除val的链表接在当前head后面，最后记得返回head

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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head==NULL)
        return head;

       ListNode* pre=removeElements(head->next,val);
        if(head->val==val)
        return pre;
        else
        {
             head->next=pre;
             return head;

        }
       
        
        
    }
};
```
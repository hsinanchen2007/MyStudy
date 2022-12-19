### 解题思路
此处撰写解题思路  
 ** 头插法，创建哨位节点L**
不断的将原链表的节点插入到L之后 

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
    ListNode* reverseList(ListNode* head)
{
    ListNode* L=new ListNode(0);
    ListNode* p=head;
    ListNode* temp;

    while(p)
    {
        temp=L->next;
        L->next=p;
        p=p->next;
        L->next->next=temp;

    }

    temp=L->next;
    delete L;
    return temp;

}

};
```
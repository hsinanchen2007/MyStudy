#### 解题思路1：反转链表法
先将链表反转，然后遍历链表，将链表中各个节点的值存储数组。
难点在于如何把链表反转
使用三个指针分别为pNode指向head节点，pNext指向head节点的下一个节点，pPre为空指针（因为head节点反转后的next指针为空，所以pPre初始化为空）。让pNode指向pPre(pPre始终为pNode的前一个节点)，然后让pNode指向下一个节点(pNext),既然前面说过**pPre始终为pNode的前一个节点**,所以pPre跟着移动，现在pPre指向pNode未移动前的节点,直到pNode为空指针
核心部分写成伪代码如下:
```
while(pNode)
{
    ListNode* pNext=pNode->next;
    pNode->next=pPre;
    pNode=pNext;
    pPre=pNode;
}
```
还需要考虑程序的鲁棒性，比如链表只有一个节点或链表为空，直接返回head即可。
所以完整代码为
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
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        ListNode* ReverseHead=ReverseList(head);
        while(ReverseHead)
        {
            res.push_back(ReverseHead->val);
            ReverseHead=ReverseHead->next;
        }
        return res;
    }
    ListNode* ReverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* pNode=head;
        ListNode* pPre=NULL;
        while(pNode)
        {
            ListNode* pNext=pNode->next;
            pNode->next=pPre;
            pPre=pNode;
            pNode=pNext;
        }
        return pPre;
    }
};
```

#### 解题思路2:栈
直接使用STL中的栈，遍历一次链表，将链表中每个节点的值存入栈中，然后再把栈中的元素读到vector中，直到栈为空。
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
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        if(head==NULL)
        {
            return res;
        }
        stack<int>stk;
        while(head)
        {
            stk.push(head->val);
            head=head->next;
        }
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
```
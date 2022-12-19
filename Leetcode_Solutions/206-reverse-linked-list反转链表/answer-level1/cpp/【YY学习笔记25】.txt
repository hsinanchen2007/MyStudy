### 解题思路
迭代法，官方方法相同：将每个元素的next都指向其前一个元素。故用到了pervious指针，current指针和future指针。
### 知识点
用到了**哑结点**:first。详情见【YY学习笔记24】。
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
    ListNode* reverseList(ListNode* head) {
        //想采用迭代
        if(head==NULL) return NULL;//错误点1：没有考虑到
        ListNode first(0);
        first.next=head;

        ListNode *prev=&first;
        ListNode *curr=head;
        ListNode *futu=head->next;
        while(curr!=NULL){
            futu=curr->next;
            curr->next=prev;

            prev=curr;
            curr=futu;
        }
        head->next=NULL;
        return prev;
    }
};
```
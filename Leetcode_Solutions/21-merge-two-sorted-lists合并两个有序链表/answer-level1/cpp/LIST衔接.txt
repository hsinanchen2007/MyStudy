### 解题思路
此处撰写解题思路
有序链表的衔接是不易的.
不是说难,而是说它要考虑的情况很多.
一个情况没有考虑到就会导致出错.
而哪怕任何一个情况未考虑到就可能导致程序的全部崩盘.
下面的这个程序还是不错的.
时间是N,空间额外的消耗为0.
重在如何利用已经存在的空间并为我所用.
总体是先是判断头部.
再是遍历两个链表往头上牵引即可.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p,*index=NULL;
        if(!l1&&!l2) return NULL;
        if(!l1&&l2) {
            p=l2,index=p; return p;
        }
        else if(l1&&!l2){
            p=l1,index=p;return p;
        }
        else 
        {
            if(l1->val<l2->val) p=l1,index=p,l1=l1->next;
            else p=l2,index=p,l2=l2->next;
        }
        while(l1&&l2)
        {
            if(l1->val<l2->val) 
            {
                index->next=l1;
                index=index->next;
                l1=l1->next;
                index->next=NULL;
            }
            else
            {
                index->next=l2;
                index=index->next;
                l2=l2->next;
                index->next=NULL;
            }
        }
        while(l1)
        {
            index->next=l1;
            index=index->next;
            l1=l1->next;
            index->next=NULL;
        }
        while(l2)
        {
            index->next=l2;
            index=index->next;
            l2=l2->next;
            index->next=NULL;
        }
        return p;
    }
};
```
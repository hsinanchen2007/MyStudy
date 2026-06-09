### 解题思路
三步；
1.找到原来链表的尾部，并计算链表的长度；
2.找到新的链表的尾部，需要从左往右寻找第(len-n-1)个
3.将原来链表头尾相连，组成一个环；新的链表的头部是尾部的下一个，然后断掉尾部即可

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* tail=head;
        int len=1;
        while(tail->next){  //tail保存尾部,同时计算长度；
            tail=tail->next;
            len++;
        }

        int n=k%len;        //取余
        if(n==0) return head;
        ListNode* newtail=head;
        int q=len-n-1;      //向右移动，
        while(q>0){         //newtail找到新的结尾
            newtail=newtail->next;
            q--;
        }

        tail->next=head;            //原先的结尾连接原来的头，组成一个环
        ListNode* newhead=newtail->next; //newhead是新的结尾下一位，是新的开头
        newtail->next=NULL;         //新的结尾阶段掉
        return newhead;
    }
};
```
### 解题思路
1. 链表的使用
链表初始化 ListNode* res=new ListNode(val);
链表的头   LIstNode* h=res;
指向链表的下一个节点    h=h->next；
2. 两个链表相加的思路
    - 设置一个进位j
    - 先计算两个链表都有数值的部分
    - 再计算链表A/B有数值的部分
    - 判断是否需要进位1
3. 这个代码较为繁琐，有更简单的请指教



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int j=0;
        ListNode* res=new ListNode(0);//list
        ListNode* h=res;//list head
        while(l1&&l2){
            int tmp=l1->val+l2->val+j;
            j=tmp/10;
            h->next=new ListNode(tmp%10);
            h=h->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int tmp=l1->val+j;
            j=tmp/10;
            h->next=new ListNode(tmp%10);
            h=h->next;
            l1=l1->next;
        }
         while(l2){
            int tmp=l2->val+j;
            j=tmp/10;
            h->next=new ListNode(tmp%10);
            h=h->next;
            l2=l2->next;
        }
        if(j==1){
            h->next=new ListNode(1);
            h=h->next;
        }
        return res->next;
    }
};
```
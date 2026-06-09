### 解题思路
两次遍历，第一次遍历求出链表长度，第二次遍历求取中间的结点。时间复杂度O(N)
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
     struct ListNode *p;
     int count=0;
     int mid;
     p= head;
     while(p!=NULL){
         count++;
         p=p->next;
     }
     mid=count/2;
     for(int i=0;i<mid;i++){
        head=head->next;  
     }
     return head;
}
```
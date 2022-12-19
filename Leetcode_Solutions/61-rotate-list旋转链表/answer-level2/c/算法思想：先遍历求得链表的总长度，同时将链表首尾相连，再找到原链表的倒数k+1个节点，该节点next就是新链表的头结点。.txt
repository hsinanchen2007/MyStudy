### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL || head->next==NULL || k==0) return head;
    int count = 1;  //用来统计链表的总结点数
    struct ListNode* temp = head;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    k%=count;
//  当k为0时，不需要旋转
    if(k==0) return head;

    //将链表首尾相连
    temp->next = head;
//  寻找倒数第K+1个节点
    for(int i = 0;i<count-k;i++){
        temp = temp->next;
    }        
    struct ListNode* newHead = temp->next;
    temp->next = NULL;
    return newHead;
}
```
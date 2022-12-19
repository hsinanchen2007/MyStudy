### 解题思路
![1584367332(1).png](https://pic.leetcode-cn.com/3f250ddeaa9c721353097f96cf572328efea3bbe16cc0baf1869f4d3e26de6c5-1584367332\(1\).png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int count=0;
    struct ListNode* head_flag=(struct ListNode*)malloc(sizeof(struct ListNode));
    head_flag=head;
    while(head){
        count++;
        head=head->next;
    }
    head=head_flag;
    if(n==count){head=head->next;return head;}
    for(int i=0;i<count;i++){
        if(i==count-n-1){
            if(n==1){head->next=NULL;break;}
            head->next=head->next->next;
            break;
        }
        head=head->next;
    }
    head=head_flag;
    return head;
}
```
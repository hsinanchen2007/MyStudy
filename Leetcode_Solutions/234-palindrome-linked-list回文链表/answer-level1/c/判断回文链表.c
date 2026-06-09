### 解题思路
先统计该链表数据个数，分别考虑奇数与偶数的两种情况；用数组暂存前一半数字，
若为奇数个，则跳过中间元素，后一半的元素与数组元素相对照；
若为偶数个，直接用后一半元素对照即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(head==NULL||head->next==NULL) return 1;
    struct ListNode *p=head; int num=0,count=0;
    while(p!=NULL){
        num++;
        p=p->next;
    }
    int half=num/2;
    int storage[half];
    while(count<half){
        storage[count]=head->val;
        head=head->next;
        count++;
    }
    if(num%2!=0) head=head->next;
    while(head!=NULL){
        count--;
        if(storage[count]!=head->val)
        return 0;
        else head=head->next;
    }
    return 1;
}
```
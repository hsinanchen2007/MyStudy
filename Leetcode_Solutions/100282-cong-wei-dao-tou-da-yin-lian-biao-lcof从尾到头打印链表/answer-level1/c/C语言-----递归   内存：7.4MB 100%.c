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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countNode(struct ListNode*head){  //测一下链表的长度,避免空间的浪费
    int count=0;
    if(!head) return 0;
    struct ListNode*p=head;
    while(p){
        p=p->next;
        count++;
    }
    return count;
}
void reverseArray(struct ListNode*head,int*ret,int*i){    //递归,从头到尾存入到数组中
    if(head!=NULL){
        reverseArray(head->next,ret,i);
        ret[(*i)++]=head->val;
    }
}
int* reversePrint(struct ListNode* head, int* returnSize){
int count=countNode(head);
int*ret=(int*)malloc(sizeof(int)*count);
int i=0;
reverseArray(head,ret,&i);
*returnSize=i;
return ret;
}
```
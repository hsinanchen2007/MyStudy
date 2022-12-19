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


int numComponents(struct ListNode* head, int* G, int GSize){
int a[10000]={0,};int i;int cnt=0;int point=0;
for(i=0;i<GSize;i++){
    a[G[i]]=1;
}
while(head!=NULL){
    if(a[head->val]==0)point=0;
    if(a[head->val]==1&&point==0){cnt++;point=1;}
    head=head->next;
}return cnt;
}
```
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
    int count=0;
    if(GSize==1)
    {
        if(head->val==G[0])
            return 1;
    }
    int m=0;
    for(head=head;head;head=head->next)
    {
        int k=0;
        for(int i=0;i<GSize;i++)
        {
            if(G[i]==head->val)
            {
                k++;
                m++;
                break;
                
            }
        }
        if(k==0&&m!=0)
        {
            count++;
            m=0;
        }
        if(head->next==NULL&&m!=0)
        {
            count++;
        }
    }
    return count;

}
```
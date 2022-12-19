### 解题思路
此处撰写解题思路
![TIM截图20200304211057.jpg](https://pic.leetcode-cn.com/e5f69496f872307e9446b9c27cec63722287de82e6b3cbc0543a62aa52a37273-TIM%E6%88%AA%E5%9B%BE20200304211057.jpg)


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
    if(!head)
        return 0;
     int *garr=(int*)malloc(sizeof(int)*10001);
    //int garr[10001];
    int cnt=0,flag=0;
    struct ListNode *g,*p;
    for(int i=0;i<GSize;i++)
        garr[G[i]]=1;
    

    p=head;
    while(p)
    {
        if(garr[p->val]==1)
        {
            if(flag==0)
                flag=1;
            p=p->next;
            if(!p)
            {
                cnt++;
                break;
            }
        }
        else
        {
            if(flag==0)
                p=p->next;
            else
            {
                cnt++;
                flag=0;
                p=p->next;
            }
        }
    }
    return cnt;

}
```
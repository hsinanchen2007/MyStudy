### 解题思路

利用了栈,还有我发现用temp1，temp2代替l1，l2来算快了好多
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
        int sum=0,flag=0;
        stack<int> ss;
        ListNode *Begin=new ListNode(0);
        //Begin=(struct ListNode*)malloc(sizeof(struct ListNode));
        //Begin->val=0;
        //Begin->next=NULL;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(flag==1) 
            {
                sum+=1;
                flag=0;
            }
            sum+=(temp1->val+temp2->val);
            if(sum>9)
            {
                flag=1;
                sum-=10;
            }
            ss.push(sum);
            sum=0;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1!=NULL&&temp2==NULL)
        {
            if(flag==1)
            {
                while(temp1!=NULL)
                {
                    if(flag==1)
                    {
                        sum+=1;
                        flag=0;
                    }
                    sum+=temp1->val;
                    if(sum>9)
                    {
                        flag=1;
                        sum-=10;
                    }
                    ss.push(sum);
                    sum=0;
                    temp1=temp1->next;

                }
            }
            else
            {
                while(temp1!=NULL)
            {ss.push(temp1->val);
            temp1=temp1->next;}
            }
        }
        else if(temp2!=NULL&&temp1==NULL)
        {
            if(flag==1)
            {
                while(temp2!=NULL)
                {
                    if(flag==1)
                    {
                        sum+=1;
                        flag=0;
                    }
                    sum+=temp2->val;
                    if(sum>9)
                    {
                        flag=1;
                        sum-=10;
                    }
                    ss.push(sum);
                    sum=0;
                    temp2=temp2->next;
                }
            }
            else
            {
                while(temp2!=NULL)
            {ss.push(temp2->val);
            temp2=temp2->next;}
            }
        }
        if(flag==1)
        {ss.push(1);}
        while(!ss.empty())
        {
            int p1;
            p1=ss.top();
            ss.pop();
            ListNode *tt=new ListNode(p1);
            tt->next=Begin->next;
            Begin->next=tt;
        }
        
        Begin=Begin->next;
        return Begin;

        }
    };
```
### 解题思路
此处撰写解题思路
逐个遍历各个链表的头节点，找到最小的值加入链表。然后更新链表当前节点后移。
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<ListNode*>headerl(lists);

        int k=lists.size();
        
        ListNode *header=NULL;
       
        ListNode *now;
        int minidex;
        ListNode *min;
        bool flag=false;

        for(ListNode *temp:headerl)
        {
            if(temp){flag=true;break;}
        }


        while(flag)
        {
            flag=false;
           
            int minval=0x3f3f3f3f;
            for(int i=0;i<k;i++)
            {
                
                if(headerl[i])
                {
                    
                   if(headerl[i]->val<minval)
                   {
                        min=headerl[i];
                        minidex=i;
                        minval=headerl[i]->val;
                        
                   }
                }
            }

            //cout<<"minidex "<<minidex<<"minval "<<minval<<endl;

            if(!header)
            {
                
                header=min;            
                now=min; 
                headerl[minidex]=headerl[minidex]->next;
            }
            else
            {
                now->next=min;
                now=min;
                headerl[minidex]=headerl[minidex]->next;
            }

            for(ListNode *temp:headerl)
            {
                if(temp)
                {
                    flag=true;
                    break;
                }
            }
        

        }

        return header;

    }
};
```
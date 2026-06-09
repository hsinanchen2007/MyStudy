### 解题思路
由于两链表长度不一定相等，所以遍历循环条件为l1||l2，这样短的可以在后面new一个0结点，将所有的加完后如果大于10，该节点-10，下一个结点+1，即进位，如果不存在就直接new一个1结点即可
### 代码
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
       ListNode* l3=new ListNode(l1->val+l2->val);
       ListNode* temp=l3;
       l1=l1->next;
       l2=l2->next;
       while(l1||l2)
       {
           if(!l1)
           {
               ListNode* p=new ListNode(0);
               l1=p;
           }
           if(!l2)
           {
               ListNode* p=new ListNode(0);
               l2=p;
           }
           ListNode* p=new ListNode(l1->val+l2->val);
           temp->next=p;
           temp=temp->next;
           l1=l1->next;
           l2=l2->next;
       }
       temp=l3;
       while(temp)
       {
            if(temp->val>=10)
            {
                temp->val-=10;
                if(temp->next)
                    temp->next->val+=1;
                else
                {
                    ListNode* p=new ListNode(1);
                    temp->next=p;
                }
            }
           temp=temp->next;
        }
        return l3;
    }
};
```
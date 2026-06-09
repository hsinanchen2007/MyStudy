### 解题思路
step1:记录链表的长度
step2:判断链表的长度是否>30
step3:相应的链表的值进行左移 
step4:对值进行求和

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
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return 0;
        ListNode* curhead=head;   
        int node_num=0;
        int sum=0;
        while(curhead!=NULL)     //判断当前结点不为空
        {
          node_num++;    
          curhead=curhead->next;
        }
        if(node_num>30)
        {
            return 0;
        }
        else
        {
         for(int i=node_num;i>=1;i--)
         {
           if(head!=NULL)
           {
            sum+=head->val<<(i-1);
            head=head->next;
           }
         }
        }
        return sum;
    }
};
```
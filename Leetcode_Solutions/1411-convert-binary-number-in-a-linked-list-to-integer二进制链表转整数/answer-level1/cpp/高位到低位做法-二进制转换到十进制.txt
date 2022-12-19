### 解题思路
反人类做法：记住从高位向低位转换的公式：anS=0;ans=2*ans+当前位的值；
正常做法看我另一个题解；

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
    int getDecimalValue(ListNode* head)
    {
        ListNode *p=head;
        int sum=0;
          while(p!=NULL)
          {
             sum=sum*2+p->val;
             p=p->next; 
          }
          return sum;

    }
        
};
        
    
   
    
       
```
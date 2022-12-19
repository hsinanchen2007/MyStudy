### 解题思路
就地进行,设置over为进位

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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* l3=new ListNode(-1),*_l3=l3;
        int over=0;

        while(l1&&l2)
        {
            int sum=l1->val+l2->val+over;
            if(sum>9) sum-=10,over=1;
            else over=0;

            _l3->next=new ListNode(sum);
            l1=l1->next,l2=l2->next,_l3=_l3->next;
        }

        ListNode* L;
        if(l1) L=l1;
        else L=l2; 

        while(L)
        {
            int sum=L->val+over;
            if(sum>9) sum-=10,over=1;
            else over=0;

            _l3->next=new ListNode(sum);
            L=L->next,_l3=_l3->next;
        }
    
        if(over) _l3->next=new ListNode(1);
        return l3->next;
    }     
};
```
![image.png](https://pic.leetcode-cn.com/91d18b6221edcb2d5a77063fb166cb2ef278be77fda73ad8dbc60841382bfaee-image.png)

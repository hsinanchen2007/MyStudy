### 解题思路
原来计算出l1,l2的值,但发现确实不行,overflow了,所以采用如下方法,使用一个变量监控进位,第一次做leetcode,记录一下,发现好像malloc不能适用,为了找个好工作继续努力!

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
        ListNode *vhead= new ListNode(-1);
        ListNode *pre =vhead;
        int t=0;
        while(l1 || l2 || t!=0){
            if(l1){
                t+=l1->val;
                l1=l1->next;
            }
            if(l2){
                t+=l2->val;
                l2=l2->next;
            }
            pre->next=new ListNode(t%10);
            t=t/10;
            pre=pre->next;
        }
        return vhead->next;
    }
};
```
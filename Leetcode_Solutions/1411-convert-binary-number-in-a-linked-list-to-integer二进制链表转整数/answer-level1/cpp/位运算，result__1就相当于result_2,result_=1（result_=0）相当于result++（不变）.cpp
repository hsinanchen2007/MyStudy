### 解题思路
位运算，result<<1就相当于result*2,result|=1（result|=0）相当于result++（不变）
同时考虑到题中条件为节点不超过30个，不需要用long long int ,int 足矣。

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
        if(head==NULL) return -1;
        int result=0;
        ListNode *p=head;
        while(p!=NULL){
            result=result<<1;
            result|=p->val;
            p=p->next;
        }
        return result;
    }
};
```
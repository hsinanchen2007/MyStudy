### 解题思路
由于是有序链表，所以，只需要考虑前后数据的大小就可以了。
这里需要注意初始赋值应该为INT_MIN，否则会出现解答错误的情况

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* res = dummy;
        
        while(res && res->next){
            if(res->val == res->next->val){
                res->next = res->next->next;
            }
            //这里加else，可以解[1,1,1]的样例
            else res = res->next;    
        }
        return dummy->next;
    }
};
```
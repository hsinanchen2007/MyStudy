### 解题思路
先数一遍链表中的元素个数，然后计算数值

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
        ListNode* count_p = head;
        int count = 0,res = 0;
        while(count_p){
            //记录链表长度
            count ++;
            count_p = count_p -> next;
        }
        while(count && head){
            //计算数值
            head -> val == 0 ? --count :
                res += pow(2,--count);
            head = head -> next;
        }
        return res;
    }
};
```
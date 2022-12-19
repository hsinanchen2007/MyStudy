### 解题思路
耗时较长，参考：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/linusda-lao-de-jie-jue-fang-an-by-adjwang/

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
  ListNode* deleteNode(ListNode* head, int val) {
        for(ListNode** result = &head; *result != NULL; result = &((*result)->next)){
            if((*result)->val == val){
                *result = (*result)->next;
                break;
            }
        }
        return head;
    }

    
};
```
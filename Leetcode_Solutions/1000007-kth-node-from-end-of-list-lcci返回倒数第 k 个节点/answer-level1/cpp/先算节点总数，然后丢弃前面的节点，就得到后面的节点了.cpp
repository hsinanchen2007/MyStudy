### 解题思路
1、先算节点总数n；
2、抛弃n-k个节点；
3、当前节点的值就是需要的结果

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
    int kthToLast(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        int number = 0;
        while(number < count - k){
            head = head->next;
            number++;
        }
        return head->val;
    }
};
```
### 解题思路
head指向的是第一个结点，别弄错了

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
    ListNode* middleNode(ListNode* head) {
        ListNode *node = head;
        int size=0;
        while(node != NULL){
            ++size;
            node = node->next;
        }
        node = head;
        int i=0;
        while(i<size/2){
            ++i;
            node = node->next;
        }
        return node;
    }
};
```
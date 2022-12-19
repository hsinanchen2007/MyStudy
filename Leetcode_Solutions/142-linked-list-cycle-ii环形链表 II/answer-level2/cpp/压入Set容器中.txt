### 解题思路
压入Set容器中

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *had = head;
        set<ListNode *>  a;
        int num = 0;
        if(head == NULL){
            return NULL;    
        }
        a.insert(had);
        num ++;
        for(;;){
            
            had = had->next;
            if(had == NULL){
                return NULL;
            }
            a.insert(had);
            num ++;
            if(a.size() < num){
                return had;
            }
        }
    }
};
```
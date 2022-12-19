### 解题思路
采用官方思路一，用哈希表来实现。

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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> a;
        ListNode *i=head;
        while(i!=NULL){
            if(a[i]==1)
                return true;
            a[i]++;
            i=i->next;
        }
        return false;

    }
};
```
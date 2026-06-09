### 解题思路
把一个个结点放入表中， 一旦表里找到相同结点，说明链表有环，否则没有

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
        map<ListNode*, int> m;
        while(head){
            if(m.count(head))  return true;
            m[head] = 1;
            head = head->next;   
        }
        return false;
    }
};
```
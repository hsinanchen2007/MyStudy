### 解题思路
此处撰写解题思路
先遍历整个整个链表并把所有元素存储在hash表中，若发现有相同，则返回
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
        if (head == nullptr) return false;
        unordered_set<ListNode*>map;
        while(head != nullptr) {
            if (map.find(head) != map.end()){
                return true;
            //exist in map
            } else {
                map.insert(head);
            //add element
            }
            head = head->next; //increase base cycle 
        }
        return false;
    }
};
```
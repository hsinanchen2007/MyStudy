### 解题思路
此处撰写解题思路

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        while(headA){
            hash.insert(headA);//将headA添加至哈希表中
            headA = headA->next;
        }
        while(headB){
            if(hash.count(headB)) return headB;//如果hash中包含headB（此时为第一个），返回headB
            headB = headB->next;
        }
        return NULL;
    }
};
```
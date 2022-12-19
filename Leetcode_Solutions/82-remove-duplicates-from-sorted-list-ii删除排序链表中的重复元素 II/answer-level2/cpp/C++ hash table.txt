### 解题思路
两次遍历，第一次遍历删除重复的元素，只保留一个，并记录下出现重复的元素(std::set)；第二次遍历，是否是hash table中出现，如果是，删除

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
        set<int> nodes;
        ListNode *dummy = new ListNode(-0x7fffffff);
        dummy -> next = head;

        ListNode* work = head;
        while ( work && work -> next ) {                    // 第一遍先找到重复的元素，送入hash table中，再删除重复的元素，
            if ( work -> next -> val == work -> val ) {
                nodes.insert(work->next->val);
                work -> next = work -> next -> next;
            } else {
                work = work -> next;
            }
        }

        work = head;
        ListNode *pre = dummy;
        while ( work ) {
            if ( nodes.end() != nodes.find(work->val) ) {
                work = work -> next;
                pre ->next = work;
            } else {
                pre = work;
                work = work -> next;
            }
        }
        return dummy -> next;
    }
};
```
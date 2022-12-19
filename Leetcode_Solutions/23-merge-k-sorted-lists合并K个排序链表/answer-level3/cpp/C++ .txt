### 解题思路
合并两个排序链表的升级版

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
    ListNode* merge2lists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        } else if(list2 == NULL) {
            return list1;
        } else if(list1->val < list2->val) {
            list1->next = merge2lists(list1->next, list2);
            return list1;
        } else if(list2->val <= list1->val) {
            list2->next = merge2lists(list1, list2->next);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0) {
            return NULL;
        } 
        if(len == 1) {
            return lists[0];
        }
        int d;
        while(len > 1) {
            d = len / 2;
            for (int i = 0; i < d; ++i) {
                lists[i] = merge2lists(lists[i], lists[i+d]);
            }
            if(len % 2 == 1) {
                lists[0] = merge2lists(lists[0], lists[len-1]);
            }
            len = len / 2;
        }
        return lists[0];
    }
};
```
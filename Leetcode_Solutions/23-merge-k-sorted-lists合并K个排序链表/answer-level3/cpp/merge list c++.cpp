### 解题思路
这道题除了暴力求解之外，有两种方式：
1） 使用优先队列， 一一比较元素，不断去除最小堆顶上的元素，然后最终组成队列；
2)  利用两两merge思想，最终把所有merge到一起； 这里两两merge可以按照顺序，可以按照二分法(1 3merge到1, 2 4merge到2， 1和2再次merge)

代码中只是朴素的两两merge  （1 2 ==> 2，3 ==> 3,4）  


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode* ret = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }

    ListNode* mergeTwoLists(ListNode* one, ListNode* two) {
        if (one == nullptr) {
            return two;
        }
        if (two == nullptr) {
            return one;
        }
        if (one->val < two->val) {
            one->next = mergeTwoLists(one->next, two);
            return one;
        } else {
            two->next = mergeTwoLists(one, two->next);
            return two;
        }
    }


};
```
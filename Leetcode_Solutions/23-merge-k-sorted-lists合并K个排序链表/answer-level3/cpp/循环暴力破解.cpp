### 解题思路
这题简单做法就是循环判断了，但是这题有两个阈值要注意，一定要判空，所以要先把其中一部分是空的先删掉。

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
        ListNode* newList = new ListNode(0);
        ListNode* tmp = newList;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr) {
                lists.erase(lists.begin() + i);
                i--;
            }
        }
        if (lists.empty()) {
            return nullptr;
        }
        
        while (!lists.empty()) {
            int minTmp = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                minTmp = min(minTmp, lists[i]->val);
            }
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]->val == minTmp) {
                    if (lists[i]->next == nullptr) {
                        lists.erase(lists.begin() + i);
                    } else {
                        lists[i] = lists[i]->next;
                    }
                    break;
                }
            }
            tmp->next = new ListNode(minTmp);
            tmp = tmp->next;
        }
        return newList->next;
    }
};
```
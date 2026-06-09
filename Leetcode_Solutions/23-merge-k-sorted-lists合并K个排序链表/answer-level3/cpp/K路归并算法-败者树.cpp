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
    void adjust(vector<int>& loser, vector<int>& key, int k, int q) {
        for (int t = (k + q) / 2; t > 0; t /= 2) {
            if (key[loser[t]] < key[q]) {
                int tmp = q;
                q = loser[t];
                loser[t] = tmp;
            }
        }
        loser[0] = q;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();          // k路
        if (k == 0) return nullptr;
        vector<int> key(k + 1, 0);
        vector<int> loser(k, 0);
        vector<ListNode*> ptrList(k, nullptr);
        for (int i = 0 ; i < k; ++i) {
            if (lists[i] == nullptr) {
                key[i] = INT_MAX;
            } else {
                key[i] = lists[i]->val;
            }
            ptrList[i] = lists[i];
            loser[i] = k;
        }
        key[k] = INT_MIN;

        for (int i = k - 1; i >= 0; --i) adjust(loser, key, k, i);

        ListNode* res = nullptr;
        ListNode* head = new ListNode(-1);
        ListNode * ptr = head;
        int q;
        while (key[loser[0]] != INT_MAX) {
            q = loser[0];
            if (ptrList[q]->next == nullptr) {
                ptr->next = ptrList[q];
                ptr = ptr->next;
                key[q] = INT_MAX;
            }
            else {
                ptr->next = ptrList[q];
                ptr = ptr->next;
                ptrList[q] = ptrList[q]->next;
                key[q] = ptrList[q]->val;
            }
            adjust(loser, key, k, q);
        }
        res = head->next;
        delete head;
        return res;
    }
};
```

败者树写的，不知为何性能反而没达到超过90%，理论上这应该是最快的算法。
ptrList[i]用来记录key[i]对应序号链表的第一个节点(随着顺序选出最小值后，ptrList[i]开始往list[i]的下一结点移动)
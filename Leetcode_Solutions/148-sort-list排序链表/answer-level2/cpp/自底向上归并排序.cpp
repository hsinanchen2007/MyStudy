### 解题思路
参考了大佬的思路写的，自底向上归并排序，有点复杂，这是我在leetcode写过最长的代码。。。

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
    ListNode* sortList(ListNode* head) {
        int length = 0;

        ListNode dummyHead(0);
        dummyHead.next = head;

        while (head) {
            length++;
            head = head->next;
        }

        //自底向上归并排序
        for (int len = 1; len < length; len *= 2) {
            ListNode *tail = head;
            head = dummyHead.next;
            dummyHead.next = NULL;

            vector<pair<ListNode*, ListNode*> > cut = cutList(head, len);

            while (cut.size() > 0) {
                head = cut[1].second->next;
                cut[1].second->next = NULL;
                pair<ListNode*, ListNode*> merged = mergeList(cut[0].first, cut[0].second, cut[1].first, cut[1].second);

                if (dummyHead.next == NULL) {
                    dummyHead.next = merged.first;
                    tail = merged.second;
                } else {
                    tail->next = merged.first;
                    tail = merged.second;
                }

                cut = cutList(head, len);
            }

            tail->next = head;
        }

        return dummyHead.next;
    }

private:
    //以长度为len切割链表，返回两个链表的头尾
    vector<pair<ListNode*, ListNode*> > cutList(ListNode* head, int len) {
        vector<pair<ListNode*, ListNode*> > result;

        if (!head) return result;

        ListNode *h1 = head, *t1 = head, *h2 = NULL, *t2 = NULL;
        int len1 = 1, len2 = 1;

        for (int i = 1; i < len && t1 != NULL; ++i) {
            t1 = t1->next;
            len1++;
        }

        if (len1 < len || t1 == NULL || t1->next == NULL) { //没法切了
            return result;
        }

        h2 = t2 = t1->next;
        t1->next = NULL;

        for (int i = 1; i < len && t2 != NULL && t2->next != NULL; ++i) {
            t2 = t2->next;
            len2++;
        }

        result.push_back(make_pair(h1, t1));
        result.push_back(make_pair(h2, t2));
        return result;
    }

    //返回合并后的头和尾
    pair<ListNode*, ListNode*> mergeList(ListNode *h1, ListNode *t1, ListNode *h2, ListNode *t2) {
        ListNode *head = NULL, *tail = NULL;

        if (h1 || h2) {
            if (!h1) return make_pair(h2, t2);
            if (!h2) return make_pair(h1, t1);
        }

        while (h1 || h2) {
            if (!h1) {
                tail->next = h2;
                tail = t2;
                break;
            } else if (!h2) {
                tail->next = h1;
                tail = t1;
                break;
            } else if (h1->val < h2->val) {
                if (!head) {
                    head = tail = h1;
                } else {
                    tail->next = h1;
                    tail = tail->next;
                }
                h1 = h1->next;
            } else {
                if (!head) {
                    head = tail = h2;
                } else {
                    tail->next = h2;
                    tail = tail->next;
                }
                h2 = h2->next;
            }
        }

        return make_pair(head, tail);
    }
};
```
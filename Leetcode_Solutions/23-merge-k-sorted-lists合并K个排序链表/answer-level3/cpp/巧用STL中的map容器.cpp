### 解题思路
遍历链表集合，每出现一个值，其在map中的值加一，最后遍历map容器(此时map容器是按键排好序的)，取出map中的值来组合成最终的链表。这种方法没有充分利用题目所给的链表已排好序这一条件。

### 代码

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> m;
        ListNode* root = new ListNode(0);
        ListNode* re = root;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != nullptr) {
                m[lists[i]->val]++;
                lists[i] = lists[i]->next;
            }
        }
        for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            int i = (*iter).second;
            while (i--) {
                root->next = new ListNode((*iter).first);
                root = root->next;
            }
        }
        root = re;
        re = re->next;
        delete root;
        return re;
    }
};
```
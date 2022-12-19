### 解题思路
为了减少遍历，先用vector把链表存下来，结果的vector肯定和链表的vector同大小，所以开辟一个同样大小的结果数组，初始化为0
然后从后往前遍历vector，每次以当前元素为准，往后找，同时访问链表数组和结果数组（动态规划思想，可以提前结束），如果在链表数组中找到更大的数，则放入结果数组，否则查看结果数组中对应位置是否为0，如果为0，则说明之后没有更大的数了，当前元素位置的结果数组中，肯定取0，否则继续往后找。

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        vector<int> result(nodes.size(), 0);
        for (int pos = nodes.size() - 1; pos >= 0; --pos) {
            for (int cur = pos + 1; cur < nodes.size(); ++cur) {
                if ((nodes[pos])->val < (nodes[cur])->val) {
                    result[pos] = (nodes[cur])->val;
                    break;
                }
                if (result[cur] == 0) { // cur位置之后，没有更大的数了，不用找了
                    result[pos] = 0;
                    break;
                }
            }
        }
        return result;
    }
};
```
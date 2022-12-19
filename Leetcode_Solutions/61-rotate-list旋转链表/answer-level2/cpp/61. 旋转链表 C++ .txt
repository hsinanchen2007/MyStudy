### 解题思路
1.把链表转化成数组进行随机操作；
2.重建链表的前后关系
3.k可能为超大数，对k模数组长度，减少计算次数

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr) {
            return head;
        }

        deque<ListNode *> nodes;
        ListNode *node = head;
        while (node != nullptr) {
            nodes.push_back(node);
            node = node->next;
        }

        int i = 0;
        k = k % nodes.size();
        while (i < k) {
            nodes.push_front(nodes.back());
            nodes.pop_back();
            i++;
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (i < nodes.size() - 1) {
                nodes[i]->next = nodes[i + 1];
            } else {
                nodes[i]->next = nullptr;
            }
        }

        return nodes[0];
    }
};
```
### 解题思路
单调递减栈
1.将链表变成数组，方便后续随机操作
2.从右向左，单调递减栈:
1)当前数字大于栈顶时，记录栈顶元素的下一个元素下标，然后弹出栈顶元素
2)当前数字小于栈顶时，将当前数字压栈

注意：栈中保存的是数组索引，不是具体值

单调栈相关题目：
下一个更大的元素II：https://leetcode-cn.com/problems/next-greater-element-ii/
下一个更大的元素I:https://leetcode-cn.com/problems/next-greater-element-i/

### 代码

```cpp
class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<ListNode *> nodes;
        deque<int> buff;
        ListNode *node = head;

        while (node) {
            nodes.push_back(node);
            node = node->next;
        }

        vector<int> result = vector<int>(nodes.size(), 0);

        for (int i = 0; i < nodes.size(); i++) {
            while (!buff.empty() && nodes[buff.front()]->val < nodes[i]->val) {
                result[buff.front()] = nodes[i]->val;
                buff.pop_front();
            }

            buff.push_front(i);
        }

        return result;
    }
};
```
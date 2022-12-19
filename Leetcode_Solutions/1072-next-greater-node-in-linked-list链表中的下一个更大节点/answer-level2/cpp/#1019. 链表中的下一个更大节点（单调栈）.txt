### 解题思路
跟题 496 类似，这道题用单调栈解决。不同的是这道题的输入是链表，要解决逆序访问的问题。尝试了两种方式：1、翻转链表；2、遍历链表并把数据存入 stack。两种方法速度差不多，前者破坏了原始的输入数据不太可取，后者遍历并存储数据到 stack 花了额外的空间。我觉得后者更适合吧。

***Talk is cheap. Show me the code.***
```cpp
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> nodes;
        stack<int> stk;
        int length = 0;
        while (head) {
            nodes.push(head->val);
            head = head->next;
            length++;
        }
        vector<int> result(length);
        while (!nodes.empty()) {
            int node = nodes.top();
            nodes.pop();
            while (!stk.empty() && node >= stk.top()) {
                stk.pop();
            }
            result[--length] = stk.empty() ? 0 : stk.top();
            stk.push(node);
        }
        return result;
    }
};
```
![1112.png](https://pic.leetcode-cn.com/7f5022b73bbd5aefa1daeb50f69f745149caa7980ffac40ee85d2b0b0ae332f6-1112.png)


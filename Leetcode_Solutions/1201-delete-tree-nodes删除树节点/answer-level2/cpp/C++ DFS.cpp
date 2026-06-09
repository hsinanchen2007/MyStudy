### 解题思路
1. 用map记录节点的孩子们；
2. 深度优先搜索，若存在父节点，则把当前节点的value和个数收归到父节点
3. 如果当前节点value为0，则把当前子树计数清零。

![image.png](https://pic.leetcode-cn.com/206b3371a366f572d02c9cedf6ccde060d50ad77a2ba774862241d3c16673f5f-image.png)


### 代码

```cpp
class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int, unordered_set<int>> childs;  // 记录每一个节点的孩子们
        for (int i = 1; i < nodes; ++i) {
            childs[parent[i]].insert(i);
        }
        stack<int> s;
        s.push(0);
        vector<int> cnts(nodes, 1);
        while (!s.empty()) {
            int t = s.top();
            if (childs[t].size() != 0) {
                for (int i : childs[t]) {
                    s.push(i);
                }
            } else {
                s.pop();
                if (t > 0) {  // 存在父节点才尝试收归操作
                    if (value[t] == 0) {  // 子树value总和为0，清零节点计数值
                        cnts[t] == 0;
                    } else {  // 节点个数和节点value收归到父节点
                        value[parent[t]] += value[t];
                        cnts[parent[t]] += cnts[t];
                    }
                    childs[parent[t]].erase(t);
                }
            }
        }
        return cnts[0];
    }
};
```
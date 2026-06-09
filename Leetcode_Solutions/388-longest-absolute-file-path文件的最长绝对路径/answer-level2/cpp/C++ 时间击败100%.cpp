注释详细
```
class Solution {
public:
    int lengthLongestPath(string input) {
        int starter = 0;
        int res = 0;
        int curLen = 0; // 在一条路径内更新路径长度
        int last_level = -1; // 上一行的层次
        stack<pair<string, int>> stk; // 要始终保证栈中只有一条路径；string为当前结点名，int为当前结点层次
        for (int i = 0; i <= input.size(); i++) {
            if (i == input.size() || input[i] == '\n') { // 取starter到i之间的结点
                string node = input.substr(starter, i - starter);
                starter = i + 1; // 更新starter
                int j = 0;
                for (; j < node.size() && node[j] == '\t'; j++); // 确定当前结点是第几层目录
                while (j <= last_level && !stk.empty()) { // 说明上一行结束了一个完整的路径
                    curLen -= stk.top().first.size(); // 需要将当前路径的长度回滚
                    stk.pop();
                    if (!stk.empty())
                        last_level = stk.top().second;
                } // 此时stk.top()是当前结点node的上一层
                // last_level是当前结点node的上一层的层次，也就是j - 1
                // curLen是当前结点node的上一层的长度
                last_level = j;
                string node_without_t = node.substr(j);
                stk.push(make_pair(node_without_t, j));
                curLen += node_without_t.size();
                if (node_without_t.find('.') != -1) {
                    // 说明当前结点是一个文件，可以更新res
                    res = max(res, curLen + j); // 注意'/'的个数等于j，需要加上
                }
            }
        }
        return res;
    }
};
```

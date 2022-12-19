### 解题思路
先求集合左右边界，找到可能的中线，然后对集合内所有点按所在行验证是否有中线的对称点。
因为坐标没有重复，所以可以直接放set里。

![image.png](https://pic.leetcode-cn.com/82b076f6ee2238bc3dc945f56a27a3b77eff09154bf61e72222e04a432f632da-image.png)

[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题，真诚欢迎大家star和follow 最近也在学习和实现lua，欢迎交流


### 代码

```cpp
class Solution {
public:
    unordered_map<int, set<int>> yx;

    bool isReflected(vector<vector<int>>& points) {
        if (points.size() == 0) return true;
        int left = INT_MAX;
        int right = INT_MIN;

        for (auto point: points) {
            left = min(point[0], left);
            right = max(point[0], right);

            yx[point[1]].insert(point[0]);
        }

        int sum = left + right;

        for (auto row: yx) {
            for (auto x: row.second) {
                if (row.second.find(sum-x) == row.second.end()) return false;
            }
        }
        
        return true;
    }
};
```
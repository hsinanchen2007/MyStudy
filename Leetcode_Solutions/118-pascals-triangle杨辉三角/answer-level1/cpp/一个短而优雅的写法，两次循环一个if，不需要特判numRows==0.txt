### 解题思路
一个比较优雅的解法，动态规划
其实直接利用返回数组作为动态规划的空间就可以了，这么写真的感觉优雅多了，甚至不需要特判numRows为零的情况。
唯一需要注意i>0的时候才需要在结尾添加1，否则不需要


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; i++) {
            ret.push_back(vector<int>());
            ret[i].push_back(1);
            for (int j = 0; j < i - 1; j++) {
                ret[i].push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
            }
            if (i > 0) ret[i].push_back(1);
        }
        return ret;
    }
};
```
时间复杂度O(numRows^2) 每一层需要遍历n*(n-1)次
空间复杂度O(numRows^2) 只有返回数组的开销，没有多余的开销
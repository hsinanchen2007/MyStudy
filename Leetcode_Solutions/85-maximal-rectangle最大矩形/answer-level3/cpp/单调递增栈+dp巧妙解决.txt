
执行用时 :20 ms, 在所有 C++ 提交中击败了89.59%的用户
内存消耗 :11.7 MB, 在所有 C++ 提交中击败了21.55%的用户


复杂度分析
```
    时间复杂度 : O(NM)。对每一行运行 力扣 84 需要 M (每行长度) 时间，运行了 N 次，共计 O(NM)。

    空间复杂度 : O(M)。我们声明了长度等于列数的数组，用于存储每一行的宽度。
```

### 代码

```cpp
class Solution {
public:
    //leetcode 84那道题的求法
    int maxArea(vector<int>& matrix) {
        stack<int> s;
        s.push(-1);
        int max_area = 0, height, width;
        for(int i = 0; i < matrix.size(); ++i) {
            while(s.top() != -1 && matrix[i] <= matrix[s.top()]) {
                height = matrix[s.top()];
                s.pop();
                width = i - s.top() - 1;
                max_area = max(max_area, height*width);
            }
            s.push(i);
        }
        while(s.top() != -1) {
            height = matrix[s.top()];
            s.pop();
            width = matrix.size() - s.top() - 1;
            max_area = max(max_area, height*width);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int size = matrix[0].size(), max_area = 0;
        vector<int>dp(size, 0);
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < size; ++j) {
                //逐行更新dp数组，dp[j]代表第j列的柱子高度
                //当matrix[i][j] == '0' ,dp[j] = 0,这很重要，仔细想一下
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            //逐行更新此时连续柱体形成的矩形面积
            max_area = max(max_area, maxArea(dp));
        }
        return max_area;
    }
};
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/e7487b1b2921060a2d8ff9a800a3657a8d3b437d46c42bafdb1d41eeac149f81-image.png)

其实这个问题，可以抽象为84 柱状图最大矩形
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
可以抽象为
[
  ["1","0","1","0","0"],
  ["1","0","1","2","3"],
  ["1","2","3","4","5"],
  ["1","0","0","1","0"]
]
就是说，以此为底边的连续i个个数，然后把每一列作为参数输入到84提的函数里

84题的解法用的是栈解法，就是先压入-1，然后依次入栈
当遇到tmp[i] < stack.top()
我们可以尝试以stack.top()为右边界的最大矩阵，
其面积为(i - 1 - ss.top()) * tmp[m]
最后拿到最大面积
### 代码

```cpp
class Solution {
public:
    int get_biggest(vector<int> &tmp) {
        int res = 0;
        stack<int> ss;
        ss.push(-1);
        int len = tmp.size();
        for (int i = 0; i < len; i++) {
            while (ss.top()!= -1 && tmp[ss.top()] > tmp[i]) {
                int m = ss.top();
                ss.pop();
                res = max(res, (i - 1 - ss.top()) * tmp[m]);
            }
            ss.push(i);
        }
        while (ss.top()!= -1) {
            int m = ss.top();
            ss.pop();
            res = max(res, (len - 1 - ss.top()) * tmp[m]);
        }
        return res;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> tmp(m, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == '1') {
                    tmp[j] = tmp[j] + 1;
                } else {
                    tmp[j] = 0;
                } 
            }
            res = max(res, get_biggest(tmp));
        }
        return res;

        


    }
};
```
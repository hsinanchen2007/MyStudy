### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8c1cebb3dbdbe87410bab3aeb12263307be9c9c61843ddd604679ffebdc9b5ea-image.png)

难得的双百

核心思路：DFS+回溯
减枝条件：
1）长度限定在平方根之内：举例：16：2 8,4 4,8 2， 8 2显然是多余的。平方根之内就是最长长度；
2）因子不能小于buff中的最大值：举例：16：2,2,4与4,2,2是没有区别的


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;

    void dfs(int n, vector<int> &buff)
    {
        if (n <= 2) {
            return;
        }

        int length = sqrt(n);
        for (int i = 2; i <= length; i++) {
            if (!buff.empty() && buff.back() > i) {
                continue;
            }

            if (n % i == 0) {
                buff.push_back(i);
                buff.push_back(n / i);
                result.push_back(buff);
                buff.pop_back();
                dfs(n / i, buff);
                buff.pop_back();
            }
        }

        return;
    }

    vector<vector<int>> getFactors(int n)
    {
        if (n == 1) {
            return vector<vector<int>>();
        }

        result.clear();
        vector<int> buff;
        dfs(n, buff);

        return result;
    }
};
```
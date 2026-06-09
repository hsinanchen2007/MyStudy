1. 杨辉三角的第 k 行等价于，二项式 (x + y)^k 的系数。
![gif.latex.gif](https://pic.leetcode-cn.com/fcde665c91e6cdda4a8009c4bff7b044bf93586c2c1fa60b4232c973686ab9a1-gif.latex.gif)
2. 按顺序计算出组合数即可。
```
class Solution {
public:
    vector<int> getRow(const int rowIndex) {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; ++i)
            ans.push_back(combination(rowIndex, i));
        return ans;
    }
    
private:
    int combination(const int m, const int i) {
        long long n = min(i, m - i);
        long long k = m - n;
        long long c = 1;
        for (long long j = 1; j <= n; ++j) {
            c *= (k + j);
            c /= j;
        }        
        return c;
    }
};
```

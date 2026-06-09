### 解题思路
1，摩尔投票寻找众数
2，验证找到的众数，符合条件输出答案即可
3，验证不符合条件，说明所有的众数都集中在数组的左侧，直接输出答案即可

### 代码

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A[0];
        int c = 1;
        int N = A.size();
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == n) {
                ++c;
            } else if (--c == 0) {
                n = A[i];
                c = 1;
            }
            if (c > 1) return n;
        }
        c = 0;
        for (auto x : A) c += x == n;
        return c > 1 ? n : A[0];
    }
};
```

![image.png](https://pic.leetcode-cn.com/a66a5106e553facf33f8dcc1e0b5e1de5ddbea2e06517c5abb3aec6fb8f65177-image.png)

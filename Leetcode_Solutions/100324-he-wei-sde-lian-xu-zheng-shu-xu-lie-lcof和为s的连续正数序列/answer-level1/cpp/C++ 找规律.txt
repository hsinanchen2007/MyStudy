### 解题思路
根据等差数列公式，从begin开始计算n个数的和sum，如果小，则n++，知道sum==target。这个时候可以将begin++，n--.继续刚刚的过程。
如果sum大于target的时候，begin++，n--；

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int n = 2;
        int begin = 1;
        while (begin < target) {
            int sum = begin * n + n*(n-1)/2;
            if (sum < target) {
                n++;
            } else if (sum == target) {
                vector<int> tmp;
                for (int i=0; i<n; i++) {
                    tmp.emplace_back(begin + i);
                }
                res.emplace_back(tmp);
                begin++;
                n=2;
            } else {
                begin++;
                n = 2;
            }
        }
        return res;
    }
};
```
### 解题思路
让前K+1个数构建出K个不同的差值，如下图所示，序列为：1、K+1、2、K、3、K-1、…其中规律为：第一个位置为1、然后下标为奇数的位置为前一个数加上interval，下标为偶数的位置为前一个数减去interval，其中interval每次减1。
![image.png](https://pic.leetcode-cn.com/b324b92462133ff92c8bb29be5ab12be5ba76e4a6fd6d30896d25273e9b60f12-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        res[0] = 1;
        for(int i = 1, interval = k; i <= k; ++i, --interval){
            res[i] = (i % 2 == 0) ? res[i-1] - interval : res[i-1] + interval;
        }
        for(int i = k+1; i < n; ++i){
            res[i] = i+1;
        }
        return res;
    }
};
```
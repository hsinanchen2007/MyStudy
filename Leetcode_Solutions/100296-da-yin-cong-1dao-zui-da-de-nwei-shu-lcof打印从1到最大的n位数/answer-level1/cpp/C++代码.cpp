### 解题思路
1、求出最大值，然后运用iota赋值

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {        
        int max = pow(10, n) - 1;
        vector<int> res;
        res.resize(max);
        iota(res.begin(), res.end(), 1);
        return res;
    }
};

2、用字符串表示最大值，然后赋值
vector<int> printNumbers(int n) {
        vector<int> res;
        string tmp;
        for (int i = 0; i < n; i++) {
            tmp += '9';
        }
        int pre = 0;
        while (to_string(pre) < tmp) {
            res.push_back(pre + 1);
            pre += 1;
        }
        return res;
    }
```
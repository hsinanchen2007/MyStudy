### 解题思路
除用位运算外，在末尾添零或一也可得到格雷码，但并不是常用的格雷码

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int> {0};
        vector<int> ret = {0,1};

        for (int i = 2; i <= n; ++i) {
            int len = ret.size();
            for (int j = 0; j < len; ++j)
                ret[j] *= 2;    // 末位加一个0
            for (int j = len-1; j>=0 ; --j)
                ret.push_back(ret[j]+1);    // 末位加一个1
        }
        return ret;
    }
};


```
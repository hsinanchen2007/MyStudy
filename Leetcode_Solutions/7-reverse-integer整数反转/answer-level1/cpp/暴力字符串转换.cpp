### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        bool negFlag = (x < 0);
        stringstream ss;
        ss << x;
        string s = ss.str();
        string ret;
        ret.resize(s.size());
        for (int i = 0; i < s.size(); i++) {
            ret.at(s.size() - 1 - i) = s.at(i);
        }
        if (negFlag) {
            ret.pop_back();
        }
        while (ret.back() == '0' && ret.size() > 1) {
            ret.pop_back();
        }

        int64_t finalRet;
        stringstream ss2;
        ss2 << ret;
        ss2 >> finalRet;
        if (negFlag) {
            finalRet = -finalRet;
        }
        if (finalRet > std::numeric_limits<int>::max() || finalRet < std::numeric_limits<int>::min()) {
            return 0;
        }
        return static_cast<int>(finalRet);
    }
};
```
### 解题思路
用stringstream，简单就完事儿了

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        stringstream ss;
        ss << s;
        string tmp;
        int ans = 0;
        while(getline(ss, tmp, ' ')){
            if(tmp != "")
            ans++;
        }
        return ans;
    }
};
```
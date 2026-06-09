### 思路一：istringstream


### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        istringstream is(s);
        int cnt = 0;
        string tmp;
        while (is >> tmp) {
            ++cnt;
        }
        return cnt;
    }
};
```

### 思路二：暴力
### 代码
```c++
class Solution {
public:
    int countSegments(string s) {
        int size = s.size(), cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') continue;
            ++cnt;
            while (i < size && s[i] != ' ') ++i;
        }
        return cnt;
    }
};
```

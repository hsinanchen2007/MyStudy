### 解题思路
提前分配内存防止溢出，还是建议复制操作吧。

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        s.reserve(s.capacity()+1);
        for (auto pos = s.begin(); pos != s.end(); ++pos){
            if (*pos == ' '){
                *pos = '%';
                s.insert(pos+1,{'2','0'});
                ++pos;
            }
        }
        return s;
    }
};
```
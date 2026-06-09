### 解题思路
1.使用istringstream，每检测到一个字符串就给count加1.

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        int counts = 0;
        string s_temp;
        istringstream is(s);
        while(is >> s_temp){
            counts++;
        }
        return counts;
    }
};
```
### 解题思路
小写字母=大写字母+32

### 代码

```cpp
class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        for(int i = 0; i < len; ++ i){
            if(str[i] <= 'Z' && str[i] >= 'A'){
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
};
```
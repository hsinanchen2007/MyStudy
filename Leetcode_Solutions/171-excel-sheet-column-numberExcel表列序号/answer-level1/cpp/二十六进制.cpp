### 解题思路
c++，转化为26进制代码就很好想了

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int num = 0, b = 0;
        for(int i = s.size()-1; i >= 0; i--){
            num += (s[i] - 'A' + 1)*pow(26, b++);
        }
        return num;
    }
};
```
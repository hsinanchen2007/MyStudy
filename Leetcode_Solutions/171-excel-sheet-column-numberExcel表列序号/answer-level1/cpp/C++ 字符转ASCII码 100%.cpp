### 解题思路
上上题的逆版本 先乘后加即可

### 代码

```cpp
/*前题的逆版本*/
class Solution {
    
public:
    int titleToNumber(string s) {
        int len = s.length();
        int res=0;
        for(int i=0;i<len;i++){
            res = res*26 + (s.at(i) - 'A' + 1);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5ffcb891708ec802fb877dc2646cb6351bb61f26619b6dec282e09d07982b2dd-image.png)

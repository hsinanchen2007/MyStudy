### 解题思路
如果S1与S2长度不等明显翻转不了。
将字符串S1的翻转区域分为AB两部分，即S1=AB，那么翻转后的S2=BA，可以看出S2+S2=BABA显然其中含有AB，因此只要查询是否S1在S2+S2中即可。
![image.png](https://pic.leetcode-cn.com/9512e6abfb71588628cb9441e8a6e74b3b04ffc260cfeea32d4746ffe77a719c-image.png)

### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        s2=s2+s2;
        return s2.npos!=s2.find(s1);
    }
};
```
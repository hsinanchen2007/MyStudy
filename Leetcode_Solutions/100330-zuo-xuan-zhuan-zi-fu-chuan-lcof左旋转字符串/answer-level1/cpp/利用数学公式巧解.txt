### 解题思路
我们将字符数组的下标0,1,2,3...n-1顺时针排列在一个圆上，就像是一张圆桌顺时针坐着n个人，题中的左旋转操作就相当于把人逆时针移动，而逆时针n位就相当于顺时针移动s.length()-n位。我们设移动后的字符串为S，S的第i位对应着s的某一位x，他们满足i = (x + s.length() - n) % s.length(),解得x = (i + n) % s.length(),这里只需要一点简单的数学知识就能解出来。

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string S = "";
        for(int i = 0; i<s.length(); i++)
        {
            int x = (i + n) % s.length();
            S += s[x];
        }
        return S;
    }
};
```
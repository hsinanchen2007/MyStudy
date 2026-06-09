### 解题思路
一顿分析发现这个就是26进制嘛，只不过用A到Z表示0到26，然后纠结幂次方的表示，突然想到pow函数（微笑），然后这个双百我好慌。。。
![批注 2020-03-20 115529.png](https://pic.leetcode-cn.com/1335e0aa378423c8e29956945a767466453944ad483e0bad3578cd4af5055f39-%E6%89%B9%E6%B3%A8%202020-03-20%20115529.png)

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        int ss=s.size();
        for(int i=0;i<ss;i++){
            sum+=((s[i]-'A'+1)*pow(26,(ss-i-1)));
        }
        return sum;
    }
};
```
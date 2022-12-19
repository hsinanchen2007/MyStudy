### 解题思路
1.理解为26进制来做吧
2.刚开始少了if的代码块，刚好能被26整除时单独考虑
### 代码
```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 26)
        {
            if (n % 26 == 0)
            {
                res += 'Z';
                n = (n - 26) / 26;
                continue;
            }
            res += (n % 26) + 64;
            n /= 26;
        }
        res += (n + 64);
        //翻转
        for (int i=0; i<res.size()/2; i++)
        {
            char temp = res[i];
            res[i] = res[res.size()-1-i];
            res[res.size()-1-i] = temp;
        }
        return res;
    }
};
```
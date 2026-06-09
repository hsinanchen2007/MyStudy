### 解题思路
# 优化的**Manacher算法**

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s)
    {
        int str_length = s.size();
        if (str_length < 2)
            return s;
        int *p = new int[str_length * 2 + 1]();
        int mx = 0, id = 0;
        int max_length = 0, max_index = 0;
        for (int i = 1; i <= str_length * 2 + 1; ++i)
        {
            p[i-1] = mx > i ? min(p[2 * id - i-1], mx - i) : 1;
            while (i - p[i-1] > 0 && i + p[i-1] <= 2 * str_length + 1)
            {
                if ((i - p[i-1]) % 2 == 1 || s.at((i - p[i-1]) / 2 - 1) == s.at((i + p[i-1]) / 2 - 1))
                {
                    p[i-1]++;
                }
                else break;
            }
            if(mx<p[i-1]+i){
                mx = p[i-1] + i;
                id = i;
            }
            if(max_length<p[i-1]-1){
                max_length = p[i-1] - 1;
                max_index = i;
            }
        }
        int start = (max_index - max_length) / 2;
        delete[] p;
        return s.substr(start, max_length);
    }
};
```
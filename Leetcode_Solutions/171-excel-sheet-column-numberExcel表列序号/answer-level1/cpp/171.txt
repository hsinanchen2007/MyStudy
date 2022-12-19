### 解题思路
d为int过不了，会溢出，改为long，ans却不会溢出

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        long d=1;
        int ans=0;
        int len=s.size();
        for(int i=len-1;i>=0;i--)
        {
            ans+=(s[i]-'A'+1)*d;
            d*=26;
        }
        return ans;
    }
};
```
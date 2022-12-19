### 解题思路
此处撰写解题思路

### 代码

```cpp
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        int n=x; int re=0;long int m=0;
        if(x<0)
            return false;
        if(x==0)
            return true;
        else
        {
            while(n!=0)
            {
                re=n%10;
                m=m*10+re;
                n/=10;
            }
        }
        if(m==x)
            return true;
        else
            return false;
    }

   
};
```
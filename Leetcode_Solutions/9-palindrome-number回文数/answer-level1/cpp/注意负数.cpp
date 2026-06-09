### 解题思路
这一题思路比较简单，需要注意的一点是，对于负数，这里直接是按照字符串表示来进行比较，所以对于负数而言，由于多了一个负号，一定不是回文。对于偶数，直接转化为字符串进行比较就可以了。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s="";
        while(x>0)
        {
            int t=x%10;
            s+=(t+'0');
            x=x/10;
        }
        int l=0;
        while(l<s.size()/2)
        {
            if(s[l]!=s[s.size()-l-1])
                return false;
            l+=1;
        }
        return true;
    }
};
```
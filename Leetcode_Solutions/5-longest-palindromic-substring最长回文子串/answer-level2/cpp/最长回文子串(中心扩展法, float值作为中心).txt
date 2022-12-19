### 解题思路
用float值作为中心,简洁明了
从(float)中心向两边扩展
共有2n-3个中心

### 代码

```cpp
class Solution 
{
public:
    int low=0,maxlen=1;

    string longestPalindrome(string& s) 
    {
        if(s.size()<=1) return s;

        for(float cen=0.5;cen<=s.size()-1.5;cen+=0.5)
            update(s,cen);

        return string(s,low,maxlen);
    }

    void update(string& s,float cen)
    {
        int l,r;

        if(cen!=(int)cen) l=cen-0.5,r=cen+0.5;
        else l=cen-1,r=cen+1;

        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            if(r-l+1>maxlen)
                low=l,maxlen=r-l+1;
            l--,r++;
        }
    }
};
```
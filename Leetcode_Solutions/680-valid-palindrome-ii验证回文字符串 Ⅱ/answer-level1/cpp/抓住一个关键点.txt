### 解题思路
抓住不匹配的字符只可能出现一次！！！
因此，记录不匹配字符的下标即可，然后分成两种可能来走即:l++ r和l r--。

### 代码

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        //1、传统方法在做时，会超时
        // string temp=s,temp1;
        // reverse(s.begin(),s.end());
        // if(temp==s)
        // return 1;
        // for(int i=0;i<temp.size();++i)
        // {
        //     temp1=temp.substr(0,i)+temp.substr(i+1);
        //     s=temp1;
        //     reverse(temp1.begin(),temp1.end());
        //     if(temp1==s)
        //     return 1;
        // }
        // return 0;
        //2、使用双指针法判断
        int bl,br,l,r,flag=0;
        l=bl=0;r=br=s.size()-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                ++l;--r;
            }
            else
            {
                if(flag==2)
                return 0;
                if(flag==0)
                {
                    bl=l;br=r;
                    ++l;
                    flag=1;
                }
                else if(flag==1)
                {
                    l=bl;r=br;
                    --r;
                    flag=2;
                }
            }
        }
        return 1;
    }
};
```
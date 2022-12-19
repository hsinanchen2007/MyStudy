### 解题思路
先比较首字母，相同的话，然后一个个比较，一旦遇到不同直接找下个相同首字母，都相同则返回首字母位置。

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0)
        return 0;
        else {
            int n=needle.size();
            int m=haystack.size();
            for(int i=0;i<m-n+1;i++)
            {
                if(haystack[i]==needle[0])
                {
                    bool flag=true;
                    for(int j=i;j<i+n;j++)
                    {
                        if(haystack[j]!=needle[j-i])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        return i;
                        break;
                    }
                }
            }
            return -1;
        }
    }
};
```
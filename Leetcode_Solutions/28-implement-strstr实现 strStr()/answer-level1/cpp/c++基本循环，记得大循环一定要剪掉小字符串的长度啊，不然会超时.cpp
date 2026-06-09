### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int idex;
        int a=haystack.size();
        int b=needle.size();
        if(b==0){
            return 0;
        }
        if(a<b)
        {
            return -1;
        }
//每次找小字符串的首字符与大字符串相等的位置，遍历
        for(int i=0;i<a-b+1;i++)
        {
            int j=0;
            if(haystack[i]==needle[0])
            {
                idex=i;
                for(j=0;j<needle.size();j++)
                {
                    if(haystack[idex]!=needle[j])
                    {
                        break;
                    }
                    else
                    {
                        idex++;
                    }
                }
                if(j==b)
                {
                    return i;
                }  
            }
            
        }
        return -1;
    }
};
```
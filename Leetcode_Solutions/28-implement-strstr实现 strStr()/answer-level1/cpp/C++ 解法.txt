### 解题思路
先找到模式串的第一个与头字符相同的的字符的位置记为n，然后在比对字符串时，若遇到不同的字符，就检查，若n与该不同字符在模式串中的位置j相比更小的话就回退j-n。
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle.size() == 0 ) return 0;
        if(needle.length() > haystack.length() ) return -1;
        int lenN=needle.size(),lenH=haystack.size(),n=lenN;
        for(int i = 1; i < lenN; i++)
        {
            if(needle.at(i) == needle.at(0) )
            {
                n = i;
                break;
            }
        }
        int j = 0,k = 0;
        for(int i = 0; i < lenH; i++)
        {
            while(haystack.at(i) == needle.at(j) )
            {
                i++,j++;
                k = i;
                if(j == lenN) return k-lenN;
                if( i >= lenH) return -1;
            }
            if(j != 0)
            {
                if(n <= j)
                {
                    i = i - (j -n+1);
                }
                else
                {
                    i--;
                }
                j = 0;
                k = 0;
            }
        }
        return -1;
    }
};
```
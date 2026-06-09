### 解题思路
常规思路：遍历haystack中haystack-needle+1长度的字符，每次遍历到haystack中第i个字符时，向后取needle长度的字符串，再与needle字符串对比，若相同则退出循环，并返回i值

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = needle.length();
        int length2 = haystack.length();
        if(length1<1)return 0;
        if(length1>length2)return -1;
        int ans=-1;
        for(int i=0;i<(length2-length1+1);i++)
        {
            if(haystack.substr(i,length1)==needle){ans=i;break;}
        }
        return ans;
    }
};
```
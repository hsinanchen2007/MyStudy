**算法思路：**利用substr函数在haystack中取与needle等长的字段进行比较

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.length();
        int len2=needle.length();
        if(len2==0) return 0;               //needle空串返回0
        for(int i=0;i<=len1-len2;i++)
        {
            if(haystack[i]!=needle[0]) continue;  //首字母不相等，直接跳过
            if(haystack.substr(i,len2)==needle)     //截取子串比较
            return i;                               //返回首字母位置
        }
        return -1;
    }
};
```

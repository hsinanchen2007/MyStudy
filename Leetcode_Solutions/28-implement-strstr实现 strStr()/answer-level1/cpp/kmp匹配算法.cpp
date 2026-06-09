### 解题思路
此处撰写解题思路
今天借此题复习了一遍kmp匹配算法。mark一下
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
         if(needle.size()==0)
             return 0;
         vector<int> next(needle.size()+1,0);
         next[0]=-1;
         int i=0;
         int j=next[0];
         int m=needle.size();
         int n=haystack.size();
         //计算mp算法中的next数组
         while(i<m)
         {
             while(j>-1&&needle[i]!=needle[j])
             {
                 j=next[j];
             }
             i++;
             j++;
             next[i]=j;
         }
         //开始mp算法匹配
         i=0;
         j=0;
         while(i<n)
         {
             while(j>-1&&haystack[i]!=needle[j])
             {
                 j=next[j];
             }
             i++;j++;
             if(j>=m)
             {
                 return i-j;
             }
         }
         return -1;
    }
};
```
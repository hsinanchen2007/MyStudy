### 解题思路


### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<n-m+1;i++){
            //因为后面比needle短，就不用考虑了，肯定不对
            int j;//i外层循环代表每次以hay的第i的字母开始比较
            for(j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]) break;//使得haysta与need一起移动，若不同直接放弃这次循环，说明这个i不对，进入下一个i的判断，所通过了我们要看j==m否，说明是否扫完了，是的话说明i就是的
            }
            if(j==m) return i;
        }
        return -1;
    }
};
```
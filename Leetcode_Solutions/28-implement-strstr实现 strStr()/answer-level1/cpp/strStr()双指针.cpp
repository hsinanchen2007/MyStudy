### 解题思路
双指针,时间复杂度O(mn),空间复杂度O(1)。
（1）i初始指向haystack第一个元素，j初始指向needle的第一个元素
（2）判断haystack[i] == needle[j]，如果成立，判断j是否到了needle最后，如果到了最后(j==m-1)，返回i-j（也就是i前j处的索引，就是needle中第一个匹配的字符在haystack出现的地方）；如果j没有到最后，那么i和j都向右移动一个位置；
（3）继续执行（2），如果haystack[i] == needle[j]不成立，那么将i回退j-1个单位，j指向needle第一个元素(j=0)，继续执行（2）。
（4）当haystack中剩余的元素n-i已经比needle中剩下的元素m-j少了，那么没有找到，return -1；
### 代码

```cpp
class Solution{
public:
    int strStr(string haystack, string needle){
        if(needle == "") return 0;
        int n = haystack.size();
        int m = needle.size();
        if(n < m ) return -1;

        int i = 0; 
        int j = 0;
        while(n-i >= m-j){
            if(haystack[i] == needle[j]){
                if(j == m-1) return i - j; 
                ++i;
                ++j;
            }else{
                i = i - j + 1;
                j = 0;
            }
        }
        
        return -1;
    }
};
```
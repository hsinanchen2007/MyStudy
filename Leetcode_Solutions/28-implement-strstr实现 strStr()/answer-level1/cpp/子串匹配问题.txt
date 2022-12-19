### 解题思路
题目要求：给你一个主串和子串，问你主串存在这样的子串吗？如果存在，那么返回开始位置。
思路：暴力匹配，定义两个指针i,j，分别指向主串和子串。如果两个指针指向的字符相同，那么进入同增状态。否则指针回退。
那么跳出循环的条件，如果存在的话，那么必然有j=maxsize.  i<=maxsize 比如 abcds  cds。 
如果不存在的话，要么 adbffjadbffj   hfhg      i=maxsize ,j=0
fhgjk  jkf   i=maxsize j<maxsize.

但是这样时间复杂度，比较高，还有KMP算法
   

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        while(i<haystack.size()&&j<needle.size()){
            if(haystack[i]==needle[j]){
                ++i;
                ++j;
            }else{
                i=i-j+1;
                j=0;
            }
        }
        // 如果j大于最大值的话，j之前的都匹配成功，而而当前j指向子串结束位置的下一个位置
        if(j>=needle.size()) return i-needle.size();
        else return -1;
    }
};
```
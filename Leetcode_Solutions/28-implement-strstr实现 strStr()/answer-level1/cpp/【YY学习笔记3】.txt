### 解题思路
使用了两层循环，外层循环用来遍历haystack，内层循环用来判断是否匹配（因为是第一遍做题，不考虑内存消耗和执行时间）。
### 知识点
string类型中的int size()函数，可以返回字符串的长度。
### 感悟
害，读题的时候需要认真呀，题中明明说needle==0时返回0，我愣是看成了返回-1。

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return 0;
        if(needle.size()>haystack.size())return -1;
        int i=0;
        int length_haystack=haystack.size(),length_needle=needle.size(),length_equ=0;
        for(i=0;i<length_haystack;i++){
            length_equ=0;
            for(int j=i;j<length_haystack&&j-i<length_needle;j++){
                if(haystack[j]==needle[j-i])
                    length_equ++;
                if(haystack[j]!=needle[j-i])
                    break;
            }
            if(length_equ==length_needle)
                return i;
        }
        return -1;
    }
};
```
### 解题思路
直接调用find函数， find函数可以在字符串中查找子字符串中出现的位置。该函数有两个参数，第一个参数是待查找的子字符串，第二个参数是表示开始查找的位置，如果第二个参数不指名的话则默认从0开始查找，也即从字符串首开始查找。


### 代码

```cpp
class Solution {
public:

    // 执行用时 :4 ms, 在所有 C++ 提交中击败了92.13% 的用户
    // 内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack=="") return -1;
        int index = haystack.find(needle);
        return index<haystack.size()?index:-1;//若找到了就返回下标。没找到就返回-1
    }
};
```
### 解题思路
    从haystack的第一位开始截取长度为needle.size()的子字符串
    然后跟needle比较
    相同的话就返回当前的位置
    不同就从第二位截取再重新对比
    以此类推
    总共需要截取 haystack.size() - needle.size() + 1 次

    思路比较简单
    但比直接使用find() 函数要好一些哈哈

    执行用时 :
    4 ms, 在所有 C++ 提交中击败了90.94%的用户
    内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++){
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
    }
};
```
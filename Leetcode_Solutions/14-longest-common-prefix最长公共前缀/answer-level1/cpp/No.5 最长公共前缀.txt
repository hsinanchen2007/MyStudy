### 解题思路
1. 将字符串按abc....进行排序，排序后，只需要判断第一个字符串和最后一个字符串的最长公共前缀即可
2. 需要注意的两个点：需要考虑一些特殊情况：（1）输入的向量为空，应返回空字符串；（2）输入的向量只包含一个元素，则返回这一个元素即可；
3. 遍历第一个字符串和最后一个字符串的每个字母，直到出现不同的字母为止；如果均相同则输出较短的字符串。
4. 这里用到了substr(0,i)函数和 条件运算符 ？：

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n==0) return "";
        if (n==1) return strs[0];

        sort(strs.begin(), strs.end());
        for(int i=0;i<min(strs[0].length(), strs[n-1].length());i++)
        {
            if(strs[0][i] != strs[n-1][i]) return strs[0].substr(0,i);
        }

        return strs[0].length() > strs[n-1].length()? strs[n-1]:strs[0];
    }
};
```
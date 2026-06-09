### 解题思路

我的解题思路大概算是**暴力解**吧。

我想到的是，如果两个字符串存在公共子串，并且这个子串能同时除尽两个字符串，那么这个子串的长度一定是两个字符串的长度的公约数。所以按照这个思路，应该找出两字符串长度的所有公约数，逐一判断以某一公约数为长度的子串（`subString`）是否能同时除尽 `str1` 和 `str2` 。

题目要求不仅要是子串，而且是**最长**子串，所以在找公约数的时候，从大到小找，并将公约数逐一存储到数组中备用。

从找到的公约数中，逐个取出公约数 `cd`（从大到小），从任一个字符串中截取以 `cd` 为长度的子串 `subString`，然后分别判断两个字符串是否能被 `subString` 除尽，如果前一个字符串不能被 `subString` 除尽，那么不必再判断后一个字符串，此时应该选取更短一点的子串继续判断。而 `subString` 的长度是从大到小取的，所以一旦遇到一个子串 `subString` 能除尽两个字符串，则可以直接将这个 `subString` 作为结果返回。

否则，知道函数运行结束，默认返回空串 `""`。

**优化：**有一个小的优化思路，写完提交之后，再看代码，发现其实并没必要将公约数存储下来，完全可以从大到小找到一个公约数就判断以这个公约数为长度的子串是否满足题意。可以同时降低空间复杂度和时间复杂度~

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len_str1 = str1.length();
        int len_str2 = str2.length();
        int small = len_str1 < len_str2 ? len_str1 : len_str2;//较短字符串的长度
        //从大到小找两字符串长度的公约数并存储到数组commonDivisor中
        for (int cd = small; cd > 0; cd--) {
            if (len_str1 % cd == 0 && len_str2 % cd == 0) {
                bool div = true;//能否被除尽
                string subString = str1.substr(0, cd);//从任一字符串中取长度为公约数cd的子串
                //判断str1是否能被subString除尽
                for (int i = 0; i < len_str1; i += cd) {
                    if (subString != str1.substr(i, cd)) {
                        div = false;
                        break;
                    }
                }
                //判断str2是否能被subString除尽
                //如果 div == false 则说明str1不能被subString除尽，不必再判断str2
                for (int i = 0; div == true && i < len_str2; i += cd) {
                    if (subString != str2.substr(i, cd)) {
                        div = false;
                        break;
                    }
                }
                //由于是从大到小判断，所以当遇到第一个能除尽两个字符串的子串即可直接返回结果
                if (div == true)
                    return subString;                
            }
        }
        return "";
    }
};
```
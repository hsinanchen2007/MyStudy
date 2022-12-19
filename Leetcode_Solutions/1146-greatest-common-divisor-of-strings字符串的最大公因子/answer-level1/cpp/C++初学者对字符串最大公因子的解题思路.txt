### 解题思路
此处撰写解题思路
说到字符串最大公因子 可能有些人包括我在内一下子摸不到字符串和公因子有啥关系
但认真看过示例后 可以得到最长字符串长度的一些性质：1.长度必<=str1/2或srt2/2（这取决于那个长度小 交小的即为被除数）；2.能够被str1和str2的长度整除  根据这两条规律将符合的整数存入一个容器中，则长度为容器中长度的字符串都有可能为最大公因子T

那么下一步就是看str1和str2中能有多少个T 再将T累加起来 最后比较是不是分别等于str1和str2


### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string T = "";
        int m = str1.length();
        int n = str2.length();
        vector<int> tmp;
        tmp.push_back(n);
        for (int i = n / 2; i >= 1; i--)
        {
            if (n % i == 0 && m % i == 0)
            {
                tmp.push_back(i);
            }
        }
        for (auto it : tmp)
        {
            T = str2.substr(0, it);
            string A, B;
            for (int k = m / it; k >= 1; k--)
            {
                A += T;
            }
            for (int j = n/ it; j >= 1; j--)
            {
                B += T;
            }
            if (A == str1 && B == str2)
                return T;
            else
                T = "";
        }
        return T;
    }
};
```
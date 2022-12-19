![12.mp4](32583d6a-4706-47ef-a1d2-2674ccfa5293)

<![1.jpg](https://pic.leetcode-cn.com/29b298096e98c6e0a5cda79dbaf55609d1c238efef9e44d470b48700cf8faaad-1.jpg),![2.jpg](https://pic.leetcode-cn.com/e5613a7eb47cc3a9e4c020a5d1923bd8fe6b84aa77fafbcde1b815668a7558c1-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c0fcc3a83a68d6e1867e6a31d6bef5b744142ff56a39d402ca2d5738f0c0ae4c-3.jpg),![1.jpg](https://pic.leetcode-cn.com/ebbfe945b6b9bff728b0fca4b9b995174e09e89a992bb5e71572843a1c8572cc-1.jpg),![2.jpg](https://pic.leetcode-cn.com/d9bb236cbce8e1d5bc9bb02df81471435991d3e1007df2c5a0563d0079d9ba05-2.jpg),![3.jpg](https://pic.leetcode-cn.com/8ebbf9b0c471c060858119d55c4cb490c89b790f3e60eefaf3a29278420d2441-3.jpg),![4.jpg](https://pic.leetcode-cn.com/532a26ffd9b2d161b1557594e25b04538de522e2260391470857a7e76514bad1-4.jpg),![5.jpg](https://pic.leetcode-cn.com/592b30ca4910f10194c7da33d04ef91ad11e71b6e2985f626c251a4b20821c3a-5.jpg)>

```cpp [-C++]
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        vector<string> tmpVec1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> tmpVec2 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> tmpVec3 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tmpVec4 = {"", "M", "MM", "MMM"};
        vector<vector<string>> store = {tmpVec1, tmpVec2, tmpVec3, tmpVec4};
        result.append(store[3][num / 1000 % 10]);
        result.append(store[2][num / 100 % 10]);
        result.append(store[1][num / 10 % 10]);
        result.append(store[0][num % 10]);
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/1736c7af27dd17ff8d32b66a8d03df338fdbeb7850e35327ef956b1e8118e768-1.jpg),![2.jpg](https://pic.leetcode-cn.com/0269e97e20770ebcb8eebff2631bf621cb8214ff48b6152be12057f16819264f-2.jpg),![3.jpg](https://pic.leetcode-cn.com/834a1887f2d29a5965a2a0ccafba80aee5716a89e6920bccff0ee0a6d5a53617-3.jpg),![1.jpg](https://pic.leetcode-cn.com/11ba2f24e317f25bc5dce6ea6b3d55b4f062a5b6286b49c95686e5b4ed549641-1.jpg),![2.jpg](https://pic.leetcode-cn.com/bbff02cfb8baa82c7d178dfd4948c4fda3b402d33b7c022c7162550d98688b21-2.jpg),![3.jpg](https://pic.leetcode-cn.com/d2370dae9ed8334316c5522ed11a804dcdce85b22a3ebb2d34769733555dff92-3.jpg),![4.jpg](https://pic.leetcode-cn.com/69d2a3d918b3eca108e16355f22b7bf1fae5420f96c4ed37c755b79d42fb2707-4.jpg),![5.jpg](https://pic.leetcode-cn.com/7dce4cb7245d83dadc3edadc52f9c19cb1492dc027e3470e02f13a7e2da80faf-5.jpg),![6.jpg](https://pic.leetcode-cn.com/f2387f7d011934133d646881cb7813a30f854689632b1b129f9f6ca950950884-6.jpg),![7.jpg](https://pic.leetcode-cn.com/dc45019c906c8e12f4e7512d2e09dacebf83b1b4e31f418ea4bf7b71b70fd729-7.jpg)>

```cpp [-C++]
class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        vector<int> store = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int storeSize = int(store.size());
        //贪心法
        for (int i = 0; i < storeSize; i++)
        {
            while (num >= store[i])
            {
                result.append(strs[i]);
                num -= store[i];
            }
        }
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/71318a2c08c30ccf8cbd50b20ff385557afefeee0abd7ef05bc345dfa8043cb3-%E7%BB%93%E5%B1%80.jpg)

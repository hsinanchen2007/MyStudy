### 解题思路
如题。
感觉我这道题的解法深刻体现了我不想事的死脑筋。

首先拿到这道题。嗯，字符串公因子。

行8，起手判断一下两字符串长度大小，如果第一个串的长度小于第二个串的长度，那就给他俩来一手两极反转。咱们从短的串开始开刀（滑稽）。（因为因子串不可能比他们当中任意一个要长嘛）
```
if(str1.size() < str2.size())
    swap(str1, str2);
```

那接下来开刀的第一步就是截合适长度的子串啦。
```
for(int i = str2.size();i > 0;i--)
```

这里我们从短串开始使用一个下标i，表示从下标0到i将要截下一个子串开始判定，长度嘛理所当然就是i。这么设置其实可以说是占了题目要求的光，因为要找到这样一个公因子子串，那两个字串的前i个字符组成的字串必然将与公因子相等，所以将头下标设置为0完全没问题哒。

然后因为公因子字串相加而组成的两个字符串，所以公因子字串的长度必然是两个字串长度的公因数。所以可以设置判断一下，这个操作貌似可以排除掉很多不符合题意的字串。
```
if(str1.size() % i != 0 || str2.size() % i != 0)
    continue;
```


那找到了符合条件长度的字串，接下来就按照题意给他们缝合还原一下呗。
```
//开始缝合还原啦
string temp = str2.substr(0, i);
string com = "";
for(int x = 0; x < (str1.size() / i); x++) 
    com += temp;
if(com.compare(str1) == 0)
    check1 = true;
com.clear();
for(int x = 0; x < (str2.size() / i); x++) 
    com += temp;
if(com.compare(str2) == 0)
    check2 = true;
if(check1 && check2)
    return temp;
```

这里设置bool变量check1和check2来检查该字串是否同时是字串1和字串2的因子字串。然后就可以直接return辣。！
### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        bool check1 = false, check2 = false;
        if(str1.size() < str2.size())
            swap(str1, str2);
        for(int i = str2.size();i > 0;i--) {
            if(str1.size() % i != 0 || str2.size() % i != 0)
                continue;
            string temp = str2.substr(0, i);
            string com = "";
            for(int x = 0; x < (str1.size() / i); x++) 
                com += temp;
            if(com.compare(str1) == 0)
                check1 = true;
            com.clear();
            for(int x = 0; x < (str2.size() / i); x++) 
                com += temp;
            if(com.compare(str2) == 0)
                check2 = true;
            if(check1 && check2)
                return temp;
        }
        return "";
    }
};
```

说实话，在运行判定的时候本菜鸡都觉得自己的解法真的好菜啊。。。不会各种骚套路，甚至都称不上是算法，最后一看大佬的题解，更觉得自己菜了，像是小孩子搭积木。。。
（但是结果好像不是特别差？）

![QQ图片20200312200652.png](https://pic.leetcode-cn.com/851fc92604d60a2d456a990be17e5a25846e536f3fd4c104778c44616f82447a-QQ%E5%9B%BE%E7%89%8720200312200652.png)

每日水题真是越来越难了。。。QAQ
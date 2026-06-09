### 解题思路
一开始我并没有想到辗转相除法，虽然最大公因子让我应该往这方面想，正准备暴力法时，我发现：
假设X是我们要求的最大公因子，那么`sub1=m*X` `sub2=n*X`,那么M和N 应该是互质的(如果m,n不是互质的，它们有最大公约数t，那么t*X才是两个字符串的最大公因子)，令X的长度为x，所以`sub1`的长度是`m*x`，`sub2`的长度为`n*x`,因此通过求出两字符串长度的最大公约数，就求出最大公因子的长度，进而就求出最大公因子。当然，这一切是建立在已知两字符串有公因子的前提下，如果它们没有公因子，这以前都是不成立的。如何判断它们是存在公因子的，只需要比较两个字符串的和，如果有公因子，那么(m+n)*X与(n+m)*X是相同的，如果没有公因子，`sub1+sub2`和`sub2+sub1`一定是不同的。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1+str2==str2+str1){
            return str1.substr(0,gcd(str1.size(),str2.size()));
        }
        else{
            return "";
        }

    }
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
};
```
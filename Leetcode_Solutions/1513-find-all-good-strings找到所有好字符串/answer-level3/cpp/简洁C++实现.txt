## 代码参考

本代码实现借鉴了[LighT的代码](https://leetcode-cn.com/problems/find-all-good-strings/solution/kmpdp-by-lightcml/)，命名参照了LeetCode的英文提示，感谢以上的帮助。

> 提示1：将DP与4种状态一起使用（pos：Int，posEvil：Int，equalToS1：Bool，equalToS2：Bool），它们计算大小为“ pos”的有效字符串的数量，其中带有字符串“ evil”的最大公共后缀(注：本代码为前缀)的大小为“ posEvil”。 当“ equalToS1”为“ true”时，当前有效字符串等于“ S1”，否则更大。 以类似的方式，当equalToS2为“ true”时，当前有效字符串等于“ S2”，否则较小。


> 提示2：要使用字符串“ evil”更新最大公共后缀(注：本代码为前缀)，请使用KMP预处理。

## 算法解释

不太熟悉[数位DP](https://oi-wiki.org/dp/number/)和[KMP](https://oi-wiki.org/string/kmp/)的朋友，可以点击链接去回顾一下。本人也是第一次在题目中使用KMP和数位DP，所以可能有些地方不太严谨，还请大家多多包涵。

* 为什么我们要使用动态规划DP？

因为这个问题中生成的字符串数可以根据更小规模（`n-1`）的生成字符串数得到，只要我们保证添加的这一个字符不会导致出现`evil`字符串即可。我们每次可以记录本串尾缀最长匹配`evil`的前缀的长度对应的生成字符串数，从`0`到`m-1`，其中`m`表示`evil`的串长，显然我们不需要考虑前缀长为`m`的情况，因为已经出现`evil`不符合要求。然后我们在下一次添加字符的时候就可以寻找新添加的字符是否能够加长之前的前缀，也就是能匹配上一个前缀后面的一个字符，如果能够加长那么这个字符能代表的数量就是上一个前缀代表的数量。

我们每次加长字符串的时候，需要对所有字符（`a`到`z`），和所有前缀长度进行搜索。但是问题来了，我们知道前缀是可能重复的，也就是较长前缀匹配的有可能此次失配，但是这个前缀的某后缀又可能与更短的前缀一样，而且这样的短前缀能够使得此次匹配成功。所以我们还同时需要从`0`开始寻找这样的短前缀，这样会使得复杂度很大，我们如何进行优化？

* 为什么我们要使用字符串匹配算法KMP的前缀数组？

接着上面提到的，这样一个失配然后重新寻找的过程和字符串匹配十分类似，KMP算法已经给了我们很好的解决方案————前缀数组。每次失配只需要根据数组跳转，就能够找到此时能重新匹配到的最长前缀，具体逻辑请参看KMP算法相关资料。所以我们需要用这样的数组来在失配的时候寻找更短前缀。

* 为什么我们要使用数位DP？

因为这道题还规定了下界`s1`和上界`s2`，我们在DP的过程中根据数位的增长同时记录与上下界的关系。数位DP就是利用了对于一个小于`s`的数，它从高到低肯定出现某一位，使得这一位上的数值小于`s`这一位上对应的数值。而之前的所有位都和`s`上的位相等。所以我们在对长度动态规划的同时记录与上下界的关系，这里我们要记录的是等于和不等于上下界的数量，之后加长字符串的时候依据这个来判断是否越界。

特别的，我们规定`i==-1`时，也就是生成串为空串的时候，匹配`evil`的最大长度是`0`，与上下界的关系都是相等，也即`equalToS1=equalToS2=1`。根据[洛谷GT考试](https://www.luogu.com.cn/problem/P3193)的题解，我们还可以使用矩阵快速幂针对其中的求和进行优化，这里不再展开。

## 代码样例

```c++
class Solution {
private:
    const static int mod=1000000007;//mod = 10^9 + 7
    long long dp[501][51][2][2]={0};//dp[pos][posEvil][equalToS1][equalToS2]
    int next[51];//next[posEvil] for maximum common prefix
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m=evil.size();
        for(int i=0,j=next[0]=-1;i<m;next[++i]=++j)//build next array KMP算法
            while(j>-1 and evil[i]!=evil[j]) j=next[j];
        for(int i=0;i<n;i++){//pos
            for(int p='a';p<='z';p++){//string[i]
                for(int j1=0;j1<m;j1++){//string[i-1] posEvil
                    int j=j1;//string[i] posEvil
                    while(j>-1 and evil[j]!=p) j=next[j]; j++;//KMP roll back KMP算法
                    for(auto k1:{0,1}){//string[i-1] equalToS1
                        for(auto l1:{0,1}){//string[i-1] equalToS2
                            int k=k1==0?0:p>s1[i]?0:p==s1[i]?1:-1;//string[i] equalToS1 数位DP
                            int l=l1==0?0:p<s2[i]?0:p==s2[i]?1:-1;//string[i] equalToS2 数位DP
                            if(k==-1 or l==-1) continue;//invalid state
                            dp[i][j][k][l]+=i==0?j1==0&&k1==1&&l1==1:dp[i-1][j1][k1][l1];
                            dp[i][j][k][l]%=mod;
                        }
                    }
                }
            }
        }//dp loop
        long long sum=0;
        for(int j=0;j<m;j++){//posEvil
            for(auto k:{0,1}){//equalToS1
                for(auto l:{0,1}){//equalToS2
                    sum=(sum+dp[n-1][j][k][l])%mod;
                }
            }
        }//calcu sum
        return sum;
    }
};//Time:O(n*26*m*m)
```

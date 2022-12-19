### 解题思路
我们先来思考两个字符串S和T在什么情况下是扰乱字符串：
首先，这两个字符串长度要想等，
其次，这两个字符串组成要一样
然后，S和T中，至少存在一个i，使得S的前半段和T的前半段扰动，S后半段和T后半段扰动；或者S前半段和T后半段扰动，S后半段和T前半段扰动；
翻译成形式语言即使：
1.length(S)==length(T)
2.sort(s)==sort(T)
3.至少存在一个整数i在[1,length(S)],使得(~符号表示是扰动字符串)：
   S(0:i)~T(0:i) && S(i:end)~T(i:end)
or S(0:i)~T(end-i:end) && S(end-i:end)~T(0:i)

这很容想到用递归的思想去做，但我们遇到S和T的时候，递归的判断是否存在这样的i就行了。
下面给出递归的伪代码：
```
isScramble(S,T){
    /*
    判断1，2条件:
    1.length(S)==length(T)
    2.sort(s)==sort(T)
    */
    end=length(S)
    for(i=1;i<=length(S);i++){
        if(isScramble(S(0:i),T(0:i)) && isScramble(S(i:end),T(i:end)))
            return true
        if(isScramble(S(0:i),T(end-i:end)) && isScramble(S(end-i:end),T(0:i)))
            return true

    }
}
```
递归的思路非常清晰，自顶向下，但是有很多重复计算，时间复杂度是N!,几乎我们碰到N!复杂度的时候就知道解法失效。
为了避免重复计算，我们只需要把递归改成动态规划，用数组来保存计算过的内容
**把自顶向下改成自底向上很重要的地方是如何找到最小的低，即是先计算什么**
从上面的递归思路来看，最下面（里面）的是对T和S进行切片计算，
并且显然是片段越短计算越简单
由此我们先从最小切片开始计算
用l表示切片的长度，逐步增加
我们用dp[i][j][L]表示S(i:i+L)和T(j:j+L)两个子串是否扰动
代码如下:
### 代码

```java
class Solution {
    public boolean isScramble(String s1, String s2) {
        if(s1.length()!=s2.length())
            return false;
        if(s1.length()==0)
            return false;
        boolean[][][] dp = new boolean[s1.length()][s2.length()][s1.length()+1];
        int n=s1.length();
        for(int i=0;i<n;i++){//切片l是1的时候直接判断两个字符是否相等就好
            for(int j=0;j<n;j++){
                dp[i][j][1]= s1.charAt(i)==s2.charAt(j);
            }
        }
        for(int l=2; l<=n;l++)//切片从小到大
            for(int i=0;i<n-l+1;i++)
                for(int j=0;j<n-l+1;j++){//依次遍历S、T
                    for(int k=1;k<l;k++){//对长度为l的S(i:i+L)和T(j:j+L)字符串模仿递归进行切片判断
                        if(dp[i][j][k]&&dp[i+k][j+k][l-k]){
                            dp[i][j][l]=true;
                            break;
                        }
                            
                        if(dp[i][j+l-k][k]&&dp[i+k][j][l-k]){
                                dp[i][j][l]=true;
                                break;
                        }
                            
                    }
                }
        return dp[0][0][n];
    }
}
```
时间复杂度n^4
空间复杂度n^3
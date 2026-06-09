### 解题思路
具体思路:
利用回文串的特性:
如果一个字串是回文字串，那么去掉左右两边的字符之后依然是回文。也可以说是一个回文字串，左右两边加上相同的字符，也是回文字串。
所以我们可以使用索引 i 和 j 来表示一个字符串从索引 i 到 j 的子串，
首先建立一个数组boolean[][] db

dp[i][j]表示索引i到j的子串是否是回文
dp[i][j] = true表示是回文，反之则为false

db的取值为: s.charAt(i) == s.charAt(j)&&j-i<2 || db[i+1][j-1]
长的子串dp[i][j]依赖于短的子串dp[i + 1][j - 1]，所以由短到长依次计算

1.先计算一个字符，全为true
2.再计算两个字符，如果两个字符一样则为true
3.然后计算大于三个字符，直到整个字符串


链接：https://juejin.im/post/5d3e92ace51d45508c2fb940


### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s.equals("")){
            return s;
        }
        int len = s.length(),left = 0, right = 0;
        // db[i][j] 表示字符串区间 [i, j] 是否为回文串
        boolean db[][] = new boolean[len][len];
         // 注意,这里的遍历与平常我们对字符串的遍历不一样
        for(int j = 0; j < len; j++){
            for(int i = 0; i <= j; i++){
                db[i][j] = (s.charAt(i) == s.charAt(j)) && (j-i <2 || db[i+1][j-1]);
                //如果是回文字符串，并且比之前的回文字符串要长，更新字符串长度，记录字符串
                if(db[i][j] && j-i > right - left){
                    left = i;
                    right = j;
                }
               
            }

        }
        return s.substring(left,right+1);

    }
}
```
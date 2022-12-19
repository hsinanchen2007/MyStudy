### 解题思路
本题又称**边界处理题**，顾名思义，考的就是边界处理，动态规划并不是难点~

**第一个代码块是“我为人人型DP递推”，由前到后递推**
状态方程不难求，难的是定义状态：dp[i]代表s[0..i]的解码方法数，状态方程有两个：
Ⅰ: dp[i] = dp[i-1] + dp[i-2] (从i=3开始，求s[0..i]就是求s[0..i-1]+s[0..i-2]的解码方法数,因为i可以自己作为一个数字,或者是s[i-1,i]作为两位数字
Ⅱ：dp[i] = dp[i-1]（这里其实已经是边界处理了，具体可以看代码，一看就懂）

**第二个代码块是“人人为我型DP递推”，由后往前递推**
状态方程同样不难求，dp[i][j]代表s[i,j]的解码方法数，从后往前递推，写出DP状态表，填表的过程就可以找出状态转移方程了，不过我的做法应该复杂了，小白勿喷~

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        if(s.charAt(0) == '0'){return 0;}
        if (s.length() == 1 && !"0".equals(s)) { return 1; }
        int[] dp = new int[s.length()];
        if(s.charAt(1) == '0' && s.charAt(0) > '2'){return 0;}
        dp[0] = 1;
        if((s.charAt(1) == '0' && s.charAt(0) <= '2')||(s.charAt(0) >= '3')||(s.charAt(0) == '2' && s.charAt(1) > '6')){
            dp[1] = 1;
        }else if(s.charAt(0) == '1' || (s.charAt(0) == '2' && s.charAt(1) <= '6')){
            dp[1] = 2;
        }
        for (int i = 2; i < dp.length; i++){
            if((s.charAt(i) == '0' && s.charAt(i-1) == '0') || (s.charAt(i) == '0' && s.charAt(i-1) > '2')){return 0;}
            if(s.charAt(i-1) == '0' 
                || (s.charAt(i-1) == '2' && s.charAt(i) > '6') 
                || (s.charAt(i-1) > '2')){
                dp[i] = dp[i-1];
                continue;
            }
            if(s.charAt(i) == '0' && s.charAt(i-1) <= '2'){dp[i] = dp[i-2];continue;}
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[dp.length - 1];
    }
}
```

```java
class Solution {
    public int numDecodings(String s) {
        if(s.charAt(0) == '0' ||(s.length() == 1 && "0".equals(s))){return 0;}
        if(s.length() == 1 && !"0".equals(s)){return 1;}
        int[][] dp = new int[s.length()][s.length()];
        for(int i = s.length() - 1; i >= 0; i--){
            for(int j = i; j < s.length(); j++){
                if(i == j && s.charAt(i) != '0'){dp[i][j] = 1;continue;}
                if(j - i >= 2){
                    String str = s.substring(i, i+2);
                    if(str.charAt(0) == '0'){dp[i][j] = 0;continue;}
                    Integer num = Integer.valueOf(str);
                    if(num > 26 || num == 0){
                        dp[i][j] = dp[i+1][j];
                        continue;
                    }
                    if(j - i == 2){
                        dp[i][j] = dp[i+1][j] +  dp[j][j];
                    }else{
                        dp[i][j] = dp[i+1][j] + dp[i+2][j];
                    }
                    continue;
                }
                String str1 = s.substring(i,j+1);
                if(Integer.valueOf(str1) <= 26 && str1.charAt(0) != '0'){
                    dp[i][j]++;
                }
                if(str1.charAt(0) != '0' && str1.charAt(1) != '0'){
                    dp[i][j]++;
                }
            }
        }
        return dp[0][s.length() - 1];
    }
}
```
### 执行结果
第一个代码块：
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :34.7 MB, 在所有 Java 提交中击败了39.38%的用户
第二个代码块：
执行用时 :108 ms, 在所有 Java 提交中击败了14.32%的用户

### 总结
**此题不太适合给动态规划入门的小白们练习，例如我，希望大家不要被这题打击到，因为在我认为它的边界太恶心了。**
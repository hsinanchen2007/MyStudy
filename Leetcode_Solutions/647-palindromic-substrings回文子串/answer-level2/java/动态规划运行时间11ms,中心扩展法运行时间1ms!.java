暴力算法的时间复杂度为n!,完全不应该考虑.
方法一:动态规划.
1. 初始化一个dp[len][len]的矩阵.` boolean[][] dp = new boolean[len][len];`
2. 对角线上的值设置为true,作为动态规划的初始条件
```  
for(i = 0; i < len; i++){
    dp[i][i] = true;
    count++;
}
```
3. 判断是否存在回文有两种情况；1：当两个字符s[n]和s[m]相邻时，只需要这两个字符相等即可增加count的值；2：当s[n] 和s[m不相邻时，此时只需要判断dp[n+1][m-1]和是s[n],s[m]是否相等即可得出结论
```
row = j;
column = i + j;
current = s.charAt(row) == s.charAt(column);//当前字符是否相等
if(current && (i == 1 || dp[row + 1][column - 1])){
    dp[row][column] = true;
    count++;
}
```
4. 对dp数组遍历的技巧，我们可以从图中看出规律
![leetcode002.png](https://pic.leetcode-cn.com/5100b41dce99d1a4617b3e00fd511e09d77c04124b68b11a105e9950ef805321-leetcode002.png)
图中同一条直线上的值有前者依赖于后者的关系，因此我们应该以对角线方向遍历
![leetcode002.png](https://pic.leetcode-cn.com/13fbcda7add461677d0b10af9c3d3620d96491dde9539d19fe87be53065e38ad-leetcode002.png)
本方法在發現一字符串不是回文串后，仍然對包含其的字符串進行回文判斷。此方法包含了冗餘的判斷，因此還有優化的地方。

方法二：分治法，对以不同字符为中心的回文分而治之，同时又将回文的长度分为奇数和偶数，奇数的中心有一个，而偶数的中心有两个
```
for(i = 0; i < s.length(); i++){
    count += countPalindrome(s, i, i);//奇數的情況
    count += countPalindrome(s, i, i + 1);//偶數的情況
}
```
有一個規律：回文串左右兩邊同時去掉一個字符仍然是回文串；反之一個字符串不是回文串，那麽他左右兩邊不論加上什麽字符都不可能是回文串，因此有以下代碼
```
 while(left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++)){
        count++;
    }
```
上述兩種方法分治法在發現一個字符串不是回文串之後即時中止了判斷，其運行時間比方法一要短很多

完整代碼：方法一
```
 public int countSubstrings(String s) {
        int len = s.length();
        if(len <= 1) return len;
        boolean[][] dp = new boolean[len][len];
        int i;
        int j;
        int row, column;
        boolean current;
        int count = 0;
        for(i = 0; i < len; i++){
            dp[i][i] = true;
            count++;
        }
        for(i = 1; i < len; i++){
            for(j = 0; j <= len - i - 1; j++){
                row = j;
                column = i + j;
                current = s.charAt(row) == s.charAt(column);
                if(current && (i == 1 || dp[row + 1][column - 1])){
                    dp[row][column] = true;
                    count++;
                }
            }
           
        }
        return count;
    }
```

方法二：
```
 public int countSubstrings(String s) {
        int count = 0;
        int i;
        for(i = 0; i < s.length(); i++){
            count += countPalindrome(s, i, i);
            count += countPalindrome(s, i, i + 1);
        }
         return count;
    }
    public int countPalindrome (String s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++)){
            count++;
        }
        return count;
    }
```

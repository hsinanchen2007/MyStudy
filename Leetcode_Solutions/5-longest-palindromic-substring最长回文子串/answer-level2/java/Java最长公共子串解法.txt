### 解题思路
利用最长公共子串进行求解

### 二维dp数组

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s == null)
            return "";
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length-1;
        while(left <= right){
            if(chars[left] != chars[right])
                swap(chars, left, right);
            left++;
            right--;
        }
        //逆序
        String reverseS = new String(chars);
        int[][] dp = new int[s.length()+1][s.length()+1];
        int maxSize = 0;
        int maxR = 0;
        int maxC = 0;
        for(int row=1; row<=s.length(); row++)
            for(int col=1; col<=s.length(); col++){
                if(reverseS.charAt(row-1) == s.charAt(col-1))
                    dp[row][col] = 1 + dp[row-1][col-1];

                if(dp[row][col] > maxSize && isPalindrome(reverseS.substring(row-dp[row-1][col-1]-1,row))){
                    maxSize = dp[row][col];
                    maxR = row;
                    maxC = col;
                }
            }

        StringBuffer stringBuffer = new StringBuffer();
        while(dp[maxR][maxC] != 0){
            stringBuffer.append(reverseS.charAt(maxR-1));
            maxC--;
            maxR--;
        }
        return stringBuffer.toString();
    }
    //判断是否回文
    public boolean isPalindrome(String str){
        int left = 0;
        int right = str.length()-1;
        while(left < right){
            if(str.charAt(left) != str.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

    public void swap(char[] chars, int i, int j){
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}
```

### 一维dp数组

```java
class Solution {
public String longestPalindrome(String s) {
        if(s == null)
            return "";
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length-1;
        while(left <= right){
            if(chars[left] != chars[right])
                swap(chars, left, right);
            left++;
            right--;
        }
        String reverseS = new String(chars);
        int[] dp = new int[s.length()+1];
        int maxSize = 0;
        int maxIndex = 0;
        for(int row=1; row<=s.length(); row++) {
            int upLeft = 0;
            for (int col = 1; col <= s.length(); col++) {
                int temp = dp[col];
                if (reverseS.charAt(row - 1) == s.charAt(col - 1))
                    dp[col] = 1 + upLeft;
                else
                    dp[col] = 0;
                if (dp[col] > maxSize && isPalindrome(s.substring(col - dp[col], col))) {
                    maxSize = dp[col];
                    maxIndex = col;
                }
                upLeft = temp;
            }
        }
        return s.substring(maxIndex-maxSize, maxIndex);
    }

    public boolean isPalindrome(String str){
        int left = 0;
        int right = str.length()-1;
        while(left < right){
            if(str.charAt(left) != str.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

    public void swap(char[] chars, int i, int j){
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}
```
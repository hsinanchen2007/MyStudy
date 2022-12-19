### 解题思路
1、假定有一个int[] dp 动态规划数组，每一个索引i对应的值表示[0,i]的回文子串个数。
       //1表示自身  
       那么dp[i+1] = dp[i]+1+([0,i-1]与i组成的字符串的回文子串个数)
    
2、假定我们有一个方法用于判断字符串是否是回文子串
        public boolean checkIsPlaindrome(String s ,int startIndex,int endIndex)
   
3、那么([0,i-1]与i组成的字符串的回文子串个数)对应的方法就是:
       int count = 0;
        for(int j = 0;j<i;j++){
             if(checkIsPlaindrome(s,j,i)){count+=1;}
        }
        return count;

4、最后就是实现是否是回文子串的方法
        public boolean checkIsPlaindrome(String s ,int startIndex,int endIndex){
                  while(start<endIndex&&s.charAt(startIndex)==s.charAt(endIndex)){
                           startIndex++;
                           endIndex--;
                   } 
                  return startIndex>=endIndex;
        }
  
### 代码

```java
class Solution {
  private boolean checkIspalindrome(String s,int startIndex,int endIndex){
        while(startIndex<=endIndex && s.charAt(startIndex)==s.charAt(endIndex)){
            startIndex++;
            endIndex--;
        }
        return startIndex>=endIndex?true:false;
    }

    private int countPalindrome(String s,int endIndex){
        int count = 0;
        for(int i = 0;i<endIndex;i++){
            if(checkIspalindrome(s,i,endIndex)){
                count+=1;
            }
        }
        return count;
    }

    /**
     * 假设dp[i]表示在第i个位置的回文子串个数,
     * 那么d[i+1] = d[i]+1(自身)+当前字符与之前字符串的组成的新回文字符串的个数
     *
     * @param s
     * @return
     */
    public int countSubstrings(String s) {
        int length = s.length();
        int lastIndex = length-1;
        //每一项代表当前位置处的回文字符串个数
        int[] dp = new int[length];
        dp[0] = 1;
        for(int i = 1;i<=lastIndex;i++){
            dp[i] = dp[i-1]+1+countPalindrome(s,i);
        }
        return dp[lastIndex];
    }
}
```
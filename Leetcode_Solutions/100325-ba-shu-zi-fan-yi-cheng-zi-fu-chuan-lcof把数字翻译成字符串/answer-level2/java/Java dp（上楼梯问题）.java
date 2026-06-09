### 解题思路
和经典的上楼梯问题一模一样！
当最某位数字和前位数字可组合成合法二位数是，此时的可能结果就是dp[i] = dp[i-1]+dp[i-2]

### 代码

```java
class Solution {
    public int translateNum(int num) {
        String str = num+"";
        int length = str.length();
        if(length==1)
            return 1;
        if(length==0)
            return 0;
        
        int[] dp = new int[length+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<length+1; i++)
        {
            if((str.charAt(i-2))!='0' && 
               (str.charAt(i-2)-'0')*10 + str.charAt(i-1)-'0'<26)
                dp[i] = dp[i-1]+dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        
        return dp[length];
        
    }
}
```
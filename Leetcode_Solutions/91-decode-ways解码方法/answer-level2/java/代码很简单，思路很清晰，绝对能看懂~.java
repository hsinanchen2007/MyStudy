### 菜鸡的解题思路
##### dp[i]记录的是当指针指到第i个字符时，会出现多少种解码方法。
#### 大佬勿喷，第一次写题解。
最简单的：第一个字符如果不是0，dp[0]一定等于1。
##### 1.特殊情况：s[i]=0，s[i-1]等于1或2：dp[i] = dp[i-2],否则直接return 0；
举例120,dp[2] = dp[0] = 1;
##### 2.(s[i]>6 && s[i-1]=2)||s[i-1]>2：dp[i] = dp[i-1]; s[i-1]s[i]组成的字符大于26
举例237，dp[2] = dp[1] = 2;
##### 3.s[i-1]=1或1<=s[i-1]<=2 && 1<=s[i]<=6,：dp[i]=dp[i-1]+dp[i-2];
举例117，dp[2] = dp[0]+dp[1] = 3;
#### 特殊处理！
当i=1的时候上文中出现了i-2的情况，如果定义的数组是s.length长度，会出现数组越界，为了处理这个问题，将数组的长度增加一位，dp[1]记录的是第1个字符，所以只要第一位字符不为0，dp[1]都等于1；为了兼容i=2(即第二位字符)的情况，将dp[0]设为1。

理解起来可能不是很顺畅，多担待。
![QQ图片20200222004413.png](https://pic.leetcode-cn.com/61a60df4e0f107a563b963e9c3aeff9d1726bf4c68e55bff6c563132fb722940-QQ%E5%9B%BE%E7%89%8720200222004413.png)


### 代码

```java
class Solution {
    public int numDecodings(String s) {
       if(s.length()<1 || s.charAt(0)=='0'){
                return 0;
            }
            int[] dp = new int[s.length()+1];
            dp[0] = 1;
            dp[1] = 1;
            for(int i=1;i<s.length();i++){
                if(s.charAt(i)=='0'){
                    if(s.charAt(i-1)=='1' || s.charAt(i-1)=='2'){
                        dp[i+1]= dp[i-1];
                    }else{
                        return 0;
                    }
                }else{
                    if(s.charAt(i-1) == '1' || (s.charAt(i-1) == '2'
                            && s.charAt(i) >= '1' && s.charAt(i) <= '6')){
                        dp[i+1] = dp[i]+dp[i-1];
                    }else{
                        dp[i+1] = dp[i];
                    }
                }
            }
            return dp[s.length()];
        }
}
```
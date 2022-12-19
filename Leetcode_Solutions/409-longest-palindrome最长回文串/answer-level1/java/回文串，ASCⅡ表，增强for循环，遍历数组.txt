### 解题思路
1.把所有出现过两次以上的字母次数取整累加ans
2.只要最后的ans和比总的字符串小，就可以直接拿一个字母放到中间

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[58];
        for(char c : s.toCharArray()){
            count[c-'A']+=1;
        }
        int  ans = 0;
        int y = 0;
        for(int x : count){
            ans += x/2*2;
            y+=x;
            }
            if(y>ans){
                ans++;
            }  
            return ans;
        }

    }
```
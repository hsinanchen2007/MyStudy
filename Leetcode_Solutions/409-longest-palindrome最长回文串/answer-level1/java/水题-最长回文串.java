### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        boolean existodd=false;
        int total=0;
        int[] nums=new int[60]; 
        for(int i=0;i<60;i++)
            nums[i]=0;       
        for(int i=0;i<s.length();i++)
            nums[s.charAt(i)-'A']++;
        for(int i=0;i<60;i++)
        {
            if(nums[i]%2==1)
            {
                existodd=true;
                total+=nums[i]-1;
            }
            else
                total+=nums[i];
        }
        if(existodd)
            total+=1;
        return total;
    }
}


//更简单的方法，来自【Sweetiee】:
/*
class Solution {
    public int longestPalindrome(String s) {
      int[] cnt = new int[58];
      for (char c : s.toCharArray()) {
         cnt[c - 'A'] += 1;
      }

      int ans = 0;
      for (int x: cnt) {
        // 字符出现的次数最多用偶数次。
        ans += x - (x & 1);
      }
      // 如果最终的长度小于原字符串的长度，说明里面某个字符出现了奇数次，那么那个字符可以放在回文串的中间，所以额外再加一。
      return ans < s.length() ? ans + 1 : ans;  
    }
}
*/
```
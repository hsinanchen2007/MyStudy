### 解题思路


### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] count =new int[123];
        for(char c:s.toCharArray())
           {count[(int)c]++;}     //统计字母的数组，count['a']即为count[97]

        int ans=0;
    for(int v:count){
       if(v%2==0){ans+=v;}
       if(v%2==1){ans+=(v/2)*2;}
       if(v%2==1&&ans%2==0){ans++;}    //遍历字母数组，只有一个奇数大小的字母能作为回文数中心
    }
  return ans;
    }
}




    
```
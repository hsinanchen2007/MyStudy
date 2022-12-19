### 解题思路
https://www.zhihu.com/people/god-jiang

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] res=new int[58];
        for(char c:s.toCharArray()){
            res[c-'A']++;
        }
        int ans=0;
        for(int v:res){
            ans+=v-(v&1);
        }
        return ans<s.length()?ans+1:ans;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if(s.equals("")||len==0){
            return 0;
        }
        int max = Integer.MIN_VALUE;
        String ans = "";
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(ans.contains(s.substring(j,j+1))){
                    max = Math.max(max,ans.length());
                    ans = "";
                    break;
                }else {
                    ans += s.substring(j,j+1);
                }
            }
        }
        max = Math.max(max,ans.length());
        return max;
    }
}
```
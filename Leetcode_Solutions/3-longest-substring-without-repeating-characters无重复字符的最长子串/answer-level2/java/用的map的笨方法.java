### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>();
        int end = 0, start = 0;
        while(end < n){
            char alpah = s.charAt(end);
            if(map.containsKey(alpah)){
                start++;
                map.clear();
                end = start;
            }
            else{
                end++;
                ans = Math.max(ans,end-start);
                map.put(alpah,end);
            }
        }
        return ans;
    }
}



```
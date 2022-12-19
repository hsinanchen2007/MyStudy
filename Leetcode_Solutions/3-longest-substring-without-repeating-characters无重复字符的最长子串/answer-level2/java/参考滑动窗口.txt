### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> map = new HashMap<>();
         int length = 0;
         int max = 0;
         int samepoint = 0;  // 标记重复位置
         boolean sameflag = false; // 记录是否重复
         if (s.length() == 0) {
             return 0;
         }
          for (int i = 0; i < s.length(); i++) {
             if (map.containsKey(s.charAt(i))) { // 如果存在
                 samepoint = Math.max(samepoint,map.get(s.charAt(i)));
                 length = i - samepoint;
                 max = Math.max(length,max);
                 sameflag = true;
             } else {
                 if (sameflag == false) {
                     length = i + 1;
                 } else {
                     length = i - samepoint;
                 }
                 max = Math.max(length,max);
             }
             map.put(s.charAt(i),i);
         }      
          return max;
    }
}
```
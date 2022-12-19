### 解题思路
1.定义一个Map key存字符，value存字符的index+1，为什么是index+1是因为在移动start的时候需要从重复的字符索引下一个索引开始。
2.循环遍历字符串，如果当前字符没有在map中则表示还没有重复，计算之前的最大子字符串的长度和当前循环位置-start的长度取两个中交大的值为最长子字符创，如果当前字符串已经在map中则表示已经重复了，那么重新计算start的开始位置
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> map = new HashMap<>();
        int ans =0;
        int start=0;
        for (int i = 0; i < s.length(); i++) {
            if(map.containsKey(s.charAt(i))){
                start = Math.max(start,map.get(s.charAt(i)));
            }
            ans = Math.max(i-start+1,ans);
            map.put(s.charAt(i),i+1);
        }
       return ans;
    }
}
```
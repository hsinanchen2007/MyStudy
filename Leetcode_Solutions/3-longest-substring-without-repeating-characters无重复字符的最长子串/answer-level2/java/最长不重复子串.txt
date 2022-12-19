### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        // 比较所有的子字符串，比较过的直接跳过

        int n = s.length();
        // 最长子串长度
        int ans = 0;

        // 记录遍历过的每个字符和对应的索引
        Map<Character, Integer> map = new HashMap<>();

        // i和j分别是子字符串的起点和终点
        for (int i=0,j=0; j<n; j++) {
            if (map.containsKey(s.charAt(j))) {
                // 起点直接跳过重复的j，i=j+1
                // 判断Max是为了避免遇到相同字符时i前移
                i = Math.max(map.get(s.charAt(j))+1, i);
            }
            // 设置字符位置
            map.put(s.charAt(j), j);
            // +1目的是i已经+1了
            ans = Math.max(ans, j-i+1);
        }
        return ans;

    }
}
```
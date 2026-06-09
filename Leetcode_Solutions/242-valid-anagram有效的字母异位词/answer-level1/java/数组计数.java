### 解题思路
遍历s 数组计数
遍历t 数组减数
判断计数数组是否存在不等于0的数

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        //异位词-词相同 排列不同的词 - 使用数组保存
        int[] count = new int[26];

        //bad-case
        if (s.length() != t.length()) {
            return false;
        }
        
        //遍历字符串s-统计字母出现的个数
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i)-'a'] += 1;
        }

        //遍历字符串t-减去字母出现的个数
        for (int i = 0; i < t.length(); i++) {
            count[t.charAt(i)-'a'] -= 1;
        }

        //判断count是否有非零值
        for (int j : count) {
            if (j != 0) {
                return false;
            }
        }

        return true;
    }
}
```
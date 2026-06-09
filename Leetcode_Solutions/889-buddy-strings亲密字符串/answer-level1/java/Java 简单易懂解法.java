### 解题思路
 分为以下五种情况：
    (1)两个字符串长度不相等直接返回 false
    (2)两个字符串中有不同的字符直接返回 false
    (3)两个字符串的所有字符构成都相同，有两个位置的字符不同，返回 true
    (4)两个字符串的所有字符构成都相同，有两个以上位置的字符不同，返回 false
    (5)两个字符串完全相同，如果有某个字符出现次数大于等于二就返回 true；否则返回 false

### 代码

```java
class Solution {
   
    public boolean buddyStrings(String A, String B) {
        // 情况一
        if (A.length() != B.length()) {
            return false;
        }
        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();
        boolean flag = false;
        // 记录 A 的字符和出现次数
        for (char c : A.toCharArray()) {
            map1.put(c, map1.getOrDefault(c, 0) + 1);
        }
        // 记录 B 的字符和出现次数
        for (char c : B.toCharArray()) {
            map2.put(c, map2.getOrDefault(c, 0) + 1);
        }
        // 遍历 map1
        for (Map.Entry<Character, Integer> entry : map1.entrySet()) {
            char c = entry.getKey();
            // 情况二：如果 map1 中的某个字符在 map2 中没有，直接返回 false
            if (map2.getOrDefault(c, 0) == 0) {
                return false;
            }
            if (!map2.get(c).equals(entry.getValue())) {
                return false;
            }
            // 如果两个字符串中有某个字符出现次数大于等于二把标志位置位 true，方便处理后面的情况三
            if (entry.getValue() >= 2) {
                flag = true;
            }
        }
        char[] arr1 = A.toCharArray();
        char[] arr2 = B.toCharArray();
        int ret = 0;
        // 遍历两个字符串，在两个字符串的所有字符构成都相同的情况下，统计不同的字符个数
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) {
                ret++;
            }
        }
        // 情况三
        if (ret == 2) {
            return true;
        }
        // 情况五
        if (ret == 0 && flag) {
            return true;
        }
        // 情况四
        return false;
    }
}
```
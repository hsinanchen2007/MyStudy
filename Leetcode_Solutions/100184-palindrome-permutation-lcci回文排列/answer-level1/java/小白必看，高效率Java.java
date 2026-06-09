### 解题思路
观察回文字符串的特性，奇数个个数的字符必须只能存在1个或0个，所以这个问题变成了统计每个字符个数的问题。
做题要透过现象看本质，方能一通百通，无脑刷题不可取。

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        int count = 0;
        for (Map.Entry entry : map.entrySet()) {
            //为奇数个字符的个数
            if ((int) entry.getValue() % 2 == 1) {
                count++;
            }
        }
       
        return count == 1 || count == 0;
    }
}
```
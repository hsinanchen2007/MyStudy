### 解题思路
就是取出所有的字符，计算这个字符出现的次数，当这个奇数次数小于2时是回文

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
            if (s.length() == 0) {
            return true;
        }
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, sum = s.length(); i < sum; i ++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                int count = map.get(c) + 1;
                map.put(c, count);
            } else {
                map.put(c, 1);
            }
        }

        int sum = 0;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue()%2 != 0) {
                sum ++;
            }
        }
        return sum < 2;
    }
}
```
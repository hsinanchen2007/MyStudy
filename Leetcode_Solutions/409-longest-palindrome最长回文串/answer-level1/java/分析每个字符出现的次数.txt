### 解题思路
分析每个字符出现的次数，出现次数偶数，则直接加出现的次数
为奇数，则加1

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        if (s.length() == 1) {
            return 1;
        }

        Map<Integer, Integer> sMap = new HashMap<Integer, Integer>();
        Integer c;
        for (int i = 0; i < s.length(); i++) {
            c = (int) s.charAt(i);
            if (sMap.containsKey(c)) {
                sMap.put(c, sMap.get(c) + 1);
            } else {
                sMap.put(c, 1);
            }
        }

            int total = 0;
        int oddCount = 0;
        Integer value = 0;
        for (Map.Entry<Integer, Integer> entry : sMap.entrySet()) {
            value = entry.getValue();
            if (value % 2 == 0) {
                total = total + value;
            } else {
                oddCount++;
                total = total + (value - 1);
            }
        }

        if (total != 0 && oddCount > 0) {
            total++;
        }

        return total > 1 ? total : 1;
    }
}
```
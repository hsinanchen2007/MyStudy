### 解题思路

先通过特殊类型的字典，计算六种特殊类型的组合，然后在拆开字符串通过字典查找进行加和，最终返回结果

### 代码

```java
class Solution {
    private static final Map<String, Integer> SPECIAL = new HashMap<String, Integer>(){{
        put("IV", 4);
        put("IX", 9);
        put("XL", 40);
        put("XC", 90);
        put("CD", 400);
        put("CM", 900);
    }};
    private static final Map<String, Integer> NORMAL = new HashMap<String, Integer>(){{
        put("I", 1);
        put("V", 5);
        put("X", 10);
        put("L", 50);
        put("C", 100);
        put("D", 500);
        put("M", 1000);
    }};

    public int romanToInt(String s) {
        int res = 0;
        for (String k : SPECIAL.keySet()) {
            if (s.contains(k)) {
                res += SPECIAL.get(k);
                s = s.replace(k, "");
            }
        }
        String[] arr = s.split("");
        for (String a : arr) {
            if (NORMAL.get(a) > 0) {
                res += NORMAL.get(a);
            }
        }
        return res;
    }
}
```
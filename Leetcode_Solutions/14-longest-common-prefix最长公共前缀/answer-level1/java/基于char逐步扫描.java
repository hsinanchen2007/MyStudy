原始的方式有可能也是高效的。
时间复杂度 (O(N * K))  n: 最短字符长度；  k: 数组长度

```java
public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        int min = Integer.MAX_VALUE;
        for (String str : strs) {
            min = Math.min(min, str.length());
        }
        if (min == 0) {
            return "";
        }

        String first = strs[0];

        int i = 0;
        while (i < min) {
            for (int j = 1; j < strs.length; j++) {
                //有一个不等于，则中断
                if (strs[j].charAt(i) != first.charAt(i)) {
                    return first.substring(0, i);
                }
            }
            i++;
        }


        return first.substring(0, i);
    }
```
### 解题思路
没啥思路，也不懂算法，就用的平时常用的java方法

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle == "" || "".equals(needle))
            return 0;
        int i = haystack.length() - needle.length();
        if (i < 0)
            return -1;

        Map<String,Integer> map = new HashMap<>();

        for (int j = 0; j <i+1 ; j++) {
            if (!map.containsKey(haystack.substring(j,j+needle.length())))
                map.put(haystack.substring(j,j+needle.length()),j);
        }
        if (map.containsKey(needle))
            return map.get(needle);

        return -1;
    }
}
```
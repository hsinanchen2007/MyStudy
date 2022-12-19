### 解题思路
map.firstEntry()
map.lastEntry()
map.higherEntry(entry.getKey())
map.lowerEntry(entry.getKey())
### 代码

```java
class Solution {
    public String sortString(String s) {
        StringBuffer sb = new StringBuffer();
        char[] chars = s.toCharArray();
        TreeMap<Character, Integer> map = new TreeMap<>();
        for (char ch : chars) {
            if (map.containsKey(ch)) {
                map.put(ch, map.get(ch) + 1);
            } else {
                map.put(ch, 1);
            }
        }
        Map.Entry<Character, Integer> entry = map.firstEntry();
        boolean ascending = true;
        while (map.size() > 0) {
            if (entry != null) {
                sb.append(entry.getKey());
                if (entry.getValue() > 1) {
                    map.put(entry.getKey(), entry.getValue() - 1);
                } else {
                    map.remove(entry.getKey());
                }
            } else {
                ascending = !ascending;
            }
            if (ascending) {
                entry = (entry != null ? map.higherEntry(entry.getKey()) : map.firstEntry());
            } else {
                entry = (entry != null ? map.lowerEntry(entry.getKey()) : map.lastEntry());
            }
        }
        return sb.toString();
    }
}
```
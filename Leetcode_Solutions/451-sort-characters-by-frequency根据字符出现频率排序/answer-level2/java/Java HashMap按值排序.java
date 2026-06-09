### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        if (null == s || 0 == s.length())
            return s;

        StringBuilder sb = new StringBuilder(s.length());

        HashMap<Character, Integer> map = new HashMap<>();

        for (char c: s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, (o1, o2) -> o2.getValue() - o1.getValue());

        for (Map.Entry<Character, Integer>t: list) {
            for (int i=0; i<t.getValue(); ++i)
                sb.append(t.getKey());
        }
        return sb.toString();
    }
}
```
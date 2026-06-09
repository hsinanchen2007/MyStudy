将哈希表的键值设为如下形式"#shift0#shift1#shift2...shiftN"，其中shiftN表示的是对某个给定的字符串，其第N位上的字符与第0位上字符的距离。如字符串"abc"，其序列化后的键值为"#0#1#2"
```java
class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        if (strings == null || strings.length == 0) return new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strings) {
            StringBuilder sb = new StringBuilder();
            for (char c : str.toCharArray()) {
                sb.append("#");
                int shift = (c - str.charAt(0) + 26) % 26;
                sb.append(shift);
            }
            String key = sb.toString();
            System.out.println(key);
            if (!map.containsKey(key)) map.put(key, new ArrayList<String>());
            map.get(key).add(str);
        }
        return new ArrayList<>(map.values());
    }
}
```

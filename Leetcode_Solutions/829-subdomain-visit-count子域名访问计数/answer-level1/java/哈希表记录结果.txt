### 解题思路
用map统计出现评率

### 代码

```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> result = new ArrayList<>();
        Map<String, Long> map = new HashMap<>();
        String[] strings;
        String domains, child;
        int index;

        for (String str : cpdomains) {
            index = -1;
            strings = str.split(" ");
            domains = strings[1];
            do {
                child = domains.substring(index + 1);
                map.put(child, map.get(child) == null ? Long.valueOf(strings[0]) : map.get(child) + Long.valueOf(strings[0]));
                index = domains.indexOf(".", index + 1);
            } while (index != -1);
        }

        Set<Map.Entry<String, Long>> set = map.entrySet();
        for (Map.Entry entry : set) {
            result.add(entry.getValue() + " " + entry.getKey());
        }

        return result;
    }
}
```
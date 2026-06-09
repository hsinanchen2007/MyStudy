### 解题思路
substring 结合indexOf很好用
利用map记录次数很好用

### 代码

```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < cpdomains.length; i++) {
            String[] strings = cpdomains[i].split(" ");
            int count = Integer.parseInt(strings[0]);
            String domain = strings[1];
            if (domain.isEmpty()) {
                continue;
            }
            map.put(domain, map.getOrDefault(domain, 0) + count);
            while (domain.indexOf(".") != -1) {
                domain = domain.substring(domain.indexOf(".") + 1);
                map.put(domain, map.getOrDefault(domain, 0) + count);
            }
        }
        List<String> results = new ArrayList<>();
        for (Map.Entry entry : map.entrySet()) {
            results.add(entry.getValue() + " " + entry.getKey());
        }
        return results;
    }
}
```
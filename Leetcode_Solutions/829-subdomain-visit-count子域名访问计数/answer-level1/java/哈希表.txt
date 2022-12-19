```java
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>(16);
        for (String cpdomain : cpdomains) {
            String[] split = cpdomain.split(" ");
            int v = Integer.parseInt(split[0]);
            String domain = split[1];
            visit(domain, map, v);
        }
        List<String> list = new ArrayList<>(map.size());
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String s = entry.getValue() + " " + entry.getKey();
            list.add(s);
        }
        return list;
    }

    private void visit(String domain, Map<String, Integer> map, int v) {
        map.put(domain, map.getOrDefault(domain, 0) + v);
        int idx = domain.indexOf('.', 0);
        while (idx != -1) {
            idx++;
            domain = domain.substring(idx);
            map.put(domain, map.getOrDefault(domain, 0) + v);
            idx = domain.indexOf('.', 0);
        }
    }
}
```

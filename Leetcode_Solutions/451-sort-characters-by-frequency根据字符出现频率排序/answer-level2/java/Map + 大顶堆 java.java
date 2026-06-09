得对api非常熟练，不在ide里写大概率是一堆bug。

```
class Solution {
    public String frequencySort(String s) {
        if(s.length() == 0) return "";
        Map<Character, Integer> map = new HashMap();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i ++) {
            map.compute(s.charAt(i), (k, v) -> v == null ? 1 : v+1);
        }
       PriorityQueue<Map.Entry<Character, Integer>> queue = new PriorityQueue<>(new Comparator<Map.Entry<Character, Integer>>() {
            @Override
            public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            queue.add(entry);
        }
        while(!queue.isEmpty()) {
            Map.Entry<Character, Integer> entry = queue.poll();
            for(int i = 0; i < entry.getValue(); i ++) sb.append(entry.getKey());
        }
        return sb.toString();
    }
}
```

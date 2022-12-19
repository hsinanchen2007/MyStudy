```java
class Solution {
    public String reorganizeString(String S) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < S.length(); i ++) {
            map.put(S.charAt(i), map.getOrDefault(S.charAt(i), 0) + 1);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (b[0] - a[0]));
        for (char k : map.keySet()) {
            pq.add(new int[] {map.get(k), (int)k});
        }
        StringBuilder sb = new StringBuilder();
        while (pq.size() >= 2) {
            int[] top = pq.poll();
            int[] top2 = pq.poll();
            int frequency1 = top[0];
            int frequency2 = top2[0];
            sb.append((char)top[1]);
            sb.append((char)top2[1]);
            if (frequency1 > 1) pq.add(new int[]{frequency1-1, (int)top[1]});
            if (frequency2 > 1) pq.add(new int[]{frequency2-1, (int)top2[1]});  
        }
        if (pq.size() >= 1) {
            if (pq.peek()[0] != 1) return "";
            sb.append((char)pq.peek()[1]);
            
        }
        
        return sb.toString();
    }
}
```
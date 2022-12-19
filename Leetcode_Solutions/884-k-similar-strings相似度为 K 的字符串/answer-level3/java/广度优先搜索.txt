```java
class Solution {
    public int kSimilarity(String source, String target) {
        Map<String, Integer> map = new HashMap<>(16);
        map.put(source, 0);
        Queue<String> queue = new ArrayDeque<>();
        queue.offer(source);
        String s;
        int i = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                s = queue.remove();
                if (s.equals(target)) {
                    break;
                }
                for (String n : getNeighbors(s, target, i)) {
                    if (!map.containsKey(n)) {
                        map.put(n, map.get(s) + 1);
                        queue.offer(n);
                    }
                }
            }
            i++;
        }
        if (map.containsKey(target)) {
            return map.get(target);
        }
        return -1;
    }

    private List<String> getNeighbors(String s, String t, int i) {
        List<String> list = new ArrayList<>();
        for (; i < s.length(); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                break;
            }
        }
        char[] chars = s.toCharArray();
        for (int j = i + 1; j < s.length(); j++) {
            if (s.charAt(j) == t.charAt(i)) {
                swap(chars, i, j);
                list.add(new String(chars));
                swap(chars, i, j);
            }
        }
        return list;
    }

    private void swap(char[] chars, int i, int j) {
        char tc = chars[i];
        chars[i] = chars[j];
        chars[j] = tc;
    }
}
```

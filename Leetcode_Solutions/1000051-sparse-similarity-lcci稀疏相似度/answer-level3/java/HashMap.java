```java
class Solution {
    public List<String> computeSimilarities(int[][] docs) {
        int len = docs.length;
        HashMap<Integer, List<Integer>> map = new HashMap<>(500 * len);
        HashMap<List<Integer>, Integer> res_map = new HashMap<>(1000);
        for (int i = 0; i < len; ++i)
            for (int num : docs[i])
                map.computeIfAbsent(num, unused -> new ArrayList<>()).add(i);

        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
            List<Integer> list = entry.getValue();
            if (list.size() < 2) continue;
            int size = list.size();
            for (int i = 0; i < size; ++i) {
                int base = list.get(i);
                for (int j = i + 1; j < size; ++j)
                    res_map.merge(Arrays.asList(base, list.get(j)), 1, (old_val, new_val) -> old_val + new_val);
            }
        }
        LinkedList<String> res = new LinkedList<>();
        for (Map.Entry<List<Integer>, Integer> entry : res_map.entrySet()) {
            List<Integer> pair = entry.getKey();
            double inter = entry.getValue();
            double union = docs[pair.get(0)].length + docs[pair.get(1)].length - inter;
            res.addLast(String.format("%d,%d: %.4f", pair.get(0), pair.get(1), inter / union));
        }
        return res;
    }
}
```

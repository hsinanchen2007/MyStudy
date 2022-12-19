```
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int kk : arr) {
            if (!map.containsKey(kk)) {
                map.put(kk, 1);
            }else {
                map.put(kk, map.get(kk)+1);
            }

        }

        for (Integer xx : map.values()) {
            set.add(xx);
        }
        if (map.size() == set.size()) {
            return true;
        }
        return false;
    }
}
```
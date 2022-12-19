# 代码
```java
class Solution {
    public int findClosest(String[] words, String word1, String word2) {
        Map<String, ArrayList<Integer>> map = new HashMap<>();
        int len = words.length;
        for (int i = 0; i < len; ++i) {
            ArrayList<Integer> list = map.computeIfAbsent(words[i], unused -> new ArrayList<>());
            list.add(i);
        }
        ArrayList<Integer> list1 = map.get(word1), list2 = map.get(word2);
        int res = Integer.MAX_VALUE, size = list2.size();
        for (int idx1 : list1) {
            int idx2 = -Collections.binarySearch(list2, idx1) - 1;
            if (idx2 > 0)
                res = Math.min(res, idx1 - list2.get(idx2 - 1));
            if (idx2 < size)
                res = Math.min(res, list2.get(idx2) - idx1);
        }
        return res;
    }
}
```

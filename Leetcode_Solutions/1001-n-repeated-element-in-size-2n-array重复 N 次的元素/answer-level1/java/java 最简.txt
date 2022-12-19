```
 public int repeatedNTimes(int[] A) {
        HashSet<Integer> set = new HashSet<>();
        for (int i : A) {
            if (!set.add(i)) return i;
        }
        throw null;
    }
```

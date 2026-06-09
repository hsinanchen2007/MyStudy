```
 public int[] intersection(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        HashSet<Integer> set = new HashSet<>();
        for (int i : nums1)
            set.add(i);
        int index = 0;
        for (int i : nums2) {
            if (set.contains(i)) {
                res[index++] = i;
                set.remove(i);
            }
        }
        return Arrays.copyOf(res, index);
    }
```

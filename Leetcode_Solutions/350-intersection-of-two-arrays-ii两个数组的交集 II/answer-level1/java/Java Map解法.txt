```
class Solution {

    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map1 = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums1.length; i++) {
            if (map1.containsKey(nums1[i])) {
                int counter = map1.get(nums1[i]);
                counter += 1;
                map1.put(nums1[i], counter);
            } else {
                map1.put(nums1[i], 1);
            }
        }
        for (int j = 0; j < nums2.length; j++) {
            if (map1.containsKey(nums2[j])) {
                int counter = map1.get(nums2[j]);
                counter -= 1;
                list.add(nums2[j]);
                if (counter == 0) {
                    map1.remove(nums2[j]);
                } else {
                    map1.put(nums2[j], counter);
                }
            }
        }
        Object[] r = list.toArray();
        int[] k = new int[r.length];
        for (int i = 0; i < r.length; i++) {
            k[i] = (int) r[i];
        }
        return k;
    }
}
```

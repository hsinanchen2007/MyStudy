```
  public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for(int i =0;i<nums1.length;i++) {
            set1.add(nums1[i]);
        }
        for(int j =0;j<nums2.length;j++) {
            if(set1.contains(nums2[j])) {
                set2.add(nums2[j]);
            }
        }
        int[] ans = new int[set2.size()];
        int k = 0;
        Iterator it = set2.iterator();
        while(it.hasNext()) {
            ans[k] = (int) it.next();
            k++;
        }
       return ans;
    }
```

用时9ms
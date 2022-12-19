哎

```
 public static int removeDuplicates(int[] nums) {
        if (nums == null || nums.length <= 0) {
            return 0;
        }
        List<Integer> list = new ArrayList<>();
        for (int a : nums) {
            if (!list.contains(a))
                list.add(a);
        }
        for (int i = 0; i < list.size(); i++) {
            nums[i] = list.get(i);
        }
        return list.size();
    }
```

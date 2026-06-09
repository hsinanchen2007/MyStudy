```
public static boolean containsDuplicate(int[] nums) {
        int[] temp = Arrays.stream(nums).distinct().toArray();
        return !(temp.length == nums.length);
    }
```


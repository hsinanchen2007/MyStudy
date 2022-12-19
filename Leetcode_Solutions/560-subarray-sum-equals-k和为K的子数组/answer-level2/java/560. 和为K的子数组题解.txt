暴力法，两层循环，k依次递减nums[i] 当为0的时候count++;

```
public class SubarraySum {
    public static int subarraySum(int[] nums, int k) {
        // 暴力法：从1开始，递减数字，如果为0则加1，然后从第二个开始。
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int m = k;
            for (int j = i; j < nums.length; j++) {
                m -= nums[j];
                if (m == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}

```

官方HashMap方法

```
public class SubarraySum {
    public int subarraySum(int[] nums, int k) {
        int sum = 0, count = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        return count;
    }
}
```

以空间换时间　统计0~n-1出现的次数
```
public int findRepeatNumber(int[] nums) {
        int[] count = new int[nums.length];
        for (int n : nums){
            if (count[n] == 1) return n;
            count[n]++;
        }
        return 0;
    }
```


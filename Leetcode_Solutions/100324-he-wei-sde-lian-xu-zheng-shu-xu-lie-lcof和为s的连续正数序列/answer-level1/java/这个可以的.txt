```
public int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList<>();
        int i = 1;
        int num = target;

        while (num > 0) {
            num -= i++;
            if (num != 0 && num % i == 0) {
                int start = num / i;
                int[] nums = new int[i];
                for (int j = start, ind = 0; j < start + i; ind++, j++) {
                    nums[ind] = j;
                }
                list.add(nums);
            }
        }
        Collections.reverse(list);
        int[][] ans = new int[0][];
        return list.toArray(ans);
    }
```

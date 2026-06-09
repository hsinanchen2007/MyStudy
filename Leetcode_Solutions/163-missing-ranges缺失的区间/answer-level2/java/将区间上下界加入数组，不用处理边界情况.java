```
public List<String> findMissingRanges(int[] nums, int lower, int upper) {
    long[] newNums = new long[nums.length + 2];
    newNums[0] = (long) lower - 1;
    newNums[nums.length + 1] = (long) upper + 1;
    for (int i = 1; i < nums.length + 1; i++) {
        newNums[i] = nums[i - 1];
    }
    List<String> result = new ArrayList<>();
    for (int i = 0; i < newNums.length - 1; i++) {
        long gap = newNums[i + 1] - newNums[i];
        if (gap == 1) {
            continue;
        } else if (gap == 2) {
            result.add(String.valueOf(newNums[i] + 1));
        } else if (gap > 2) {
            result.add((newNums[i] + 1) + "->" + (newNums[i + 1] - 1));
        }
    }
    return result;
}
```

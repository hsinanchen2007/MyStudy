### 解题思路

直接使用生成全排列的方式解决本题。

### 代码

```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        if (nums.length == 0) return Collections.emptyList();
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        Integer[] boxedNums = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        do {
            result.add(Arrays.stream(boxedNums).collect(Collectors.toList()));
        } while (nextPermutation(boxedNums));
        return result;
    }

    private boolean nextPermutation(Integer[] nums) {
        int pos = nums.length - 1;
        while (pos > 0 && nums[pos] <= nums[pos - 1]) pos--;
        if (pos == 0) return false;
        int pos2 = nums.length - 1;
        while (pos2 >= pos && nums[pos2] <= nums[pos - 1]) pos2--;
        swap(nums, pos - 1, pos2);

        for (int i = 0; i < (nums.length - pos) / 2; i++) {
            swap(nums, pos + i, nums.length - 1 - i);
        }
        return true;
    }

    private void swap(Integer[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
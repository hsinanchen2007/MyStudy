0ms
```
class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> resList = new ArrayList<>();
        // 处理数组为空的情况
        if (nums.length == 0){
            if (lower < upper) {
                resList.add(lower + "->" + upper);
            } else {
                resList.add("" + lower);
            }
            return resList;
        }
        // 处理lower
        if (lower != nums[0]) {
            if (lower == nums[0]-1) {
                resList.add("" + lower);
            }
            if (lower < nums[0]-1) {
                resList.add(lower + "->" + (nums[0]-1));
            }
        }
        // 处理nums
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i]==nums[i+1]) {
                continue;
            }
            if (nums[i+1] == nums[i] + 2) {
                resList.add("" + (nums[i] + 1));
            } else if (nums[i+1] > nums[i] + 2) {
                resList.add((nums[i]+1) + "->" + (nums[i+1]-1));
            }
        }
        // 处理upper(强制转型为double防止出错)
        if (upper != nums[nums.length-1]) {
            if (upper == nums[nums.length-1]+1) {
                resList.add("" + upper);
            }
            if ((double)upper > (double)(nums[nums.length-1]+1)) {
                resList.add((nums[nums.length-1]+1) + "->" + upper);
            }
        }
        return resList;
    }
}
```

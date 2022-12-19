```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new LinkedList<>();
        if (nums == null || nums.length < 4) return res;
        Arrays.sort(nums);
        for (int i = 0;i < nums.length - 3;i ++) {
            // 因为包含负数，所以也不能根据第一个值与目标值的大小来判断后面有没有满足的值
            // if (nums[i] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            // 最小的四个数加起来都比target大，说明后面不可能有值了
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
                break;
            // 此轮最大的四个数加起来还是比target小，说明第一个数不够大，则continue
            if (nums[i] + nums[nums.length -3] + nums[nums.length - 2] 
                + nums[nums.length - 1] < target) 
                continue;
            for (int j = i + 1;j < nums.length - 2;j ++) {
                // 下面注释的这一句话不正确，不能因为第二个数与目标值的大小来判断后面是否有满足的值
                // if (nums[j] > target) break;
                if (j != i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                // 最小的四个数大于target，直接就break
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) 
                    break;
                // 本轮最大的四个值加起来小于target，说明第二个数不够大，则continue
                if (nums[i] + nums[j] + nums[nums.length - 2] + nums[nums.length - 1] < target) 			       continue;
                int L = j + 1, R = nums.length - 1;
                while (L < R) {
                    int tmpSum = nums[i] + nums[j] + nums[L] + nums[R];
                    if (tmpSum == target) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[L], nums[R]));
                        while (L < R && nums[L] == nums[L + 1]) L ++;
                        while (L < R && nums[R] == nums[R - 1]) R --;
                        L ++;
                        R --;
                    } else if (tmpSum < target) {
                        L ++;
                    } else {
                        R --;
                    }
                }
            }
        }
        return res;
    }
}
```
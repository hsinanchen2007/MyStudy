### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    /**
     * 暴力 回溯法
     */
    public boolean canPartitionKSubsets(int[] nums, int k) {
        // 一些基本条件的满足判断
        if (nums.length <= 0) {
            return false;
        }
        Arrays.sort(nums);
        int maxIndex = nums.length - 1;
        int target = Arrays.stream(nums).sum() / k;
        // 判断nums数组中的最大值不能大于平均值,  平均值不能为小数
        if (nums[maxIndex] > target || Arrays.stream(nums).sum() % k != 0) {
            return false;
        }
        // 用来判断nums对应位置的数字是否已经计算过,used默认都为false(没有使用过)
        boolean[] used = new boolean[nums.length];
        return backTracking(nums, k, target, 0, 0, used);
    }

    /**
     * @param nums   目标数据
     * @param k      可以分割的set个数
     * @param target 目标值(每个set的和,也就是nums数据的平均值)
     * @param cur    已经算出的值
     * @param index  缓存索引(用于回溯)
     * @param used   对应nums中的数字是否使用过
     * @return
     */
    private boolean backTracking(int[] nums, int k, int target, int cur, int index, boolean[] used) {
        // 当k为0时代表已经把数据全都处理完了(到这一步说明前边已经将数据分割完成)
        if (k == 0) {
            return true;
        }
        // 表明计算出一组
        if (cur == target) {
            // 什么情况下k-1(已经分割出一组数据的情况下-1)
            return backTracking(nums, k - 1, target, 0, 0, used);
        }

        // 循环判断nums中index索引之后的数据和cur相加是否小于等于target
        for (int i = index; i < nums.length; i++) {
            // i 没有使用过, 并且小于等于目标值,才继续递归
            if (!used[i] && cur + nums[i] <= target) {
                used[i] = true;
                // 这块k不减,应该这个递归还是在计算第k组数据
                if (backTracking(nums, k, target, cur + nums[i], i + 1, used)) {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
}
```
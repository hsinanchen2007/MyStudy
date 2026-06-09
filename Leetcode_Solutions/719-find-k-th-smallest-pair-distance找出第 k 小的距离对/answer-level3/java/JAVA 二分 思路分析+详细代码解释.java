**思路：**
1、题目要求第K个最小距离，所以如果我们有一个有序数组记录着所有可能的最小距离，那么问题就可以变成一个最简单的二分法求解了；
2、如果有这样一组数[1, 2, 2, 4, 5, 6]，要求第K小的数，该怎么办呢？
（1）取 mid=2，通过判断数组中小于等于 2 的数量 count，就可以得到收缩的方向；
（2）如果 count < K, 那么就应该向右侧收缩，即 left = mid + 1；
（3）否则向左侧收缩，即 right = mid。

**过程：**
1、可能的最小距离数组：[0, 原数组中最大的数 - 原数组中最小的数]；
2、在该最小距离数组中寻找第K个最小距离；
（1）取到 mid 之后，要怎么判断收缩的方向呢？
（2）可以计算出原数组中距离小于等于 mid 的个数，如果 个数 < K 的话，说明mid肯定在第K个之前，那么就应该要向右侧收缩
3、如何计算原数组中距离小于等于mid的个数？
（1）从左向右依次遍历数组中的值；
（2）取1个指针向后移动，指针所指的位置 - 该遍历的值 始终要小于等于 K；
（3）最后指针所指的位置 - 该遍历的位置，即为以该遍历的位置开头的所有符合要求的距离组合；
（4）画图理解：
 ![IMG_20200319_151906.jpg](https://pic.leetcode-cn.com/765fe977efe78577c2c8b3ab9f03dd82f69aaa5003fcdaf7fcc0857c181ff57f-IMG_20200319_151906.jpg)
注：每次遍历的时候 end 指针不需要再重新复原到 i 的位置，因为数组是有序的，即 i - (i-1) >= 0，上一轮遍历的结果是 end - (i-1) <= K，所以对于本轮来说，end - i <= K 一定成立，所以继续从 end 的位置向后寻找即可。

**代码：**
```
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        // 数组排序
        Arrays.sort(nums);
        int size = nums.length;
        
        // 最小距离的最小值
        int left = 0;
        // 最小距离的最大值
        int right = nums[size-1] - nums[0];
        while (left < right) {
            // 左中位数
            int mid = (left + right) >>> 1;
            if (findPairs(nums, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // 计算距离小于等于目标值的组合数
    private int findPairs (int[] nums, int target) {
        int size = nums.length;
        int count = 0;
        int end = 0;
        for (int i = 0; i < size; i++) {
            while (end + 1 < size && nums[end+1] - nums[i] <= target) {
                ++end;
            }
            count += end - i;
        }
        return count;
    }
}
```

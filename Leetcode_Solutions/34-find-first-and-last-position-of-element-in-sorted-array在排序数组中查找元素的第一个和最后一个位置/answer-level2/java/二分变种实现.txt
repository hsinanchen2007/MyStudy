### 解题思路
考点：指定时间算法复杂度，log（n），首先想到回溯、递归、二分，此处是有序，二分最好
思路：二分查找变种，设置标志位进行找最小索引还是最大索引
时间复杂度不到2log(n)，也就是log(n)，空间复杂度O(1)
总结：灵活使用二分查找基本算法，进行变种实现高效查询

### 代码

```java
class Solution {
        public int[] searchRange(int[] nums, int target) {
        //特判
        if (nums.length == 0) {
            return new int[] {-1, -1};
        } else if (nums.length == 1) {
            int i = nums[0] == target ? 0 : -1;
            return new int[]{i, i};
        }
        //查找第一个位置 sign == 0
        int lowIndex = binarySerachFirst(nums, 0, nums.length -1, target, 0);
        //查找最后一个位置 sign == 1
        int highIndex = binarySerachFirst(nums, 0, nums.length -1, target, 1);
        return new int[] {lowIndex, highIndex};
    }
    //查找第一个位置&找到最后一个元素
    public static int binarySerachFirst(int[] nums,int left, int right, int target, int sign) {
        int lowIndex = -1;
        while (left <= right) {
            int inV = (left + right) / 2;
            //如果找到值，继续往左边找，直到找到最小索引&如果找到值，继续往右边找，直到找到最大索引
            if (nums[inV] == target) {
                lowIndex = inV;
                if (sign == 0) {
                    right = inV - 1;
                } else if (sign == 1) {
                    left = inV + 1;
                }
            } else if (nums[inV] < target) {
                left = inV + 1;
            } else {
                right = inV - 1;
            }
        }
        return lowIndex;
    }
}
```
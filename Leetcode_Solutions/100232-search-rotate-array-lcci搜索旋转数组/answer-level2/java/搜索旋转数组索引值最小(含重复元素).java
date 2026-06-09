今天看到小浩算法的一句二分查找关键语句，‘**二分查找的本质，其实就是通过收敛查找空间，找到目标值的一种方式**’
所以下面一气呵成写完了代码
主要思路为如果能确定在二分的哪个区间则移动left或者right锁定对应的区间，否则left++收敛查找空间继续循环
其中需要注意的是因为该题为要寻找索引值最小，所以只有当left下标与目标元素相等时才可以认为为目标索引，否则只做收敛空间的动作


class Solution {
    public int search(int[] nums, int target) {
         int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            //目标元素和left相同 直接返回 因为left就是索引值最小的
            if (target == nums[left]) {
                return left;
            }//目标元素和mid相同，因为要寻找的是索引值最小的 所以区间锁定在左侧包含mid值
            else if (target == nums[mid]) {
                right = mid;
            }//右侧为升序
            else if (nums[mid] < nums[right]) {
                //target确定在右侧
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }//target在左侧
                else {
                    right = mid - 1;
                }
            }//左侧为升序
            else if (nums[mid] > nums[left]) {
                if (nums[left] < target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }//不确定在哪一侧，left向前移位，进行新的循环
             else {
                left++;
            }
        }
        return -1;
    }
}
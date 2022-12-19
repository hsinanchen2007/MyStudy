# 将数组a[4,5,6,7,0,1,2]看成两段递增子数组m[4,5,6,7] n[0,1,2] target = 0
# target直接可以通过与a[0]比较得出在哪个子数组中
1. target<a[0]则target在子数组n中
2. 由于子数组n是递增数组，所以可以通过while (nums[j - 1] < nums[j])循环控制一直在子数组n中寻找target
# 详细代码如下：
```
public static int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        //处理数组长度为1情况
        if(nums.length==1){
            if (target == nums[0]) {
                return 0;
            }else{
                return -1;
            }
        }
        int i = 0, j = nums.length - 1;
        //若target<a[0]则target在后段数组中
        if (target < nums[i]) {
            //循环判断一直在后段数组寻找
            while (nums[j - 1] < nums[j]) {
                //若找到target结束
                if (target == nums[j]) {
                    return j;
                }
                //当j=0时结束while
                if (--j == 0) {
                    break;
                }
            }
            //判断后段数组最后一个值是否是target
            if (target == nums[j]) {
                return j;
            }
            return -1;
        } else {
            //若target>a[0]则target在前段数组中
            while (nums[i + 1] > nums[i]) {
                //若找到target结束
                if (target == nums[i]) {
                    return i;
                }
                //当i=nums.length-1结束循环
                if (++i == nums.length-1) {
                    break;
                }
            }
            //判断前段数组最后一个值是否是target
            if (target == nums[i]) {
                return i;
            }
            return -1;
        }
    }
```
# 新手上路，感觉判断条件欠佳，希望大家帮改正！

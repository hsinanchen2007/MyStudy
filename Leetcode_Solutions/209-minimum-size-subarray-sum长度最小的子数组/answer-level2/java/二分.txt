### 解题思路
我做这道题的二分法有点绕，主要是边界问题；
首先我写的二分查找是返回大于等于目标数的元素索引，如果目标大于所有值返回-1.

原数组nums = [2,3,1,2,4,3]
前i项和数组sums = [0,2,5,6,8,12,15]
如果从nums的第0项开始找，即找[2,3,1,2] = 8 > 7,也就是nums的第0,1,2,3项，
那么怎么用sums的数组表示呢，nums从第0项开始对应sums从第一项开始找，
即sums[4] - sums[0] = 8 - 0 = 8,这里sums的第四项就是用二分查找到的，
![IMG_20191212_164602.jpg](https://pic.leetcode-cn.com/2e847f1abebbf011c5f2015cc1a2201d00b0c521db2f705eca3644bc55da33f2-IMG_20191212_164602.jpg)
若在target大于所有sums中的数字，二分会返回-1，即没有满足的子数组



### 代码

```java
public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int result = Integer.MAX_VALUE;
        int[] sums = new int[nums.length + 1];
        for(int i = 1; i < sums.length; i++){
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for(int i = 1; i < sums.length; i++){
            int tmp = lowerBound(sums, 0, sums.length, s + sums[i - 1]);
            if(tmp != -1){
                result = Math.min(result, tmp - i + 1);
            }
        }
        if(result == Integer.MAX_VALUE){
            return 0;
        }
        return result;
    }
    private int lowerBound(int[] nums, int L, int R, int target){
        while(L < R){
            int mid = L + (R - L) / 2;
            if(target <= nums[mid]){
                R = mid;
            }
            else{
                L = mid + 1;
            }
        }
        if(L == nums.length) return -1;
        return L;
    }
}
```
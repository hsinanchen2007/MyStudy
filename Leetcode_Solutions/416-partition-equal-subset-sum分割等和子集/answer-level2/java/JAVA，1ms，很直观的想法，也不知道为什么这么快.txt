首先计算数组总和，如果是奇数，则不可能平分，直接返回false，否则计算平分数avg用于后续；
将数组的数分为2堆，left和right，一个数可能放在left，也可能放在right，分两路递归，
当left堆或者right堆等于avg,说明存在平分子集，若其中一堆大于avg，则不存在；
若都小于avg，则继续递归。
```
class Solution {
    private int avg;
    public boolean canPartition(int[] nums) {
        int len = nums.length;
        if (len<2) return false;
        avg = 0;
        for (int i=0; i<len; i++) {
            avg += nums[i];
        }
        if (avg%2==1)
            return false;
        avg = avg / 2;
        //Arrays.sort(nums);
        return core(nums, len-1, 0, 0);
        
    }
    private boolean core(int[] nums, int ind, int left, int right) {
        if (ind<0) return false;
        if (left==avg||right==avg)
            return true;
        if (left>avg||right>avg)
            return false;
        boolean res;
        res = core(nums, ind-1, left+nums[ind], right);
        if (res) return true;
        res = core(nums, ind-1, left, right+nums[ind]);
        if (res) return true;
        return false;
    }
}
```

- 算是相当暴力的算法
- 先合并
- 再排序
- 最后取中位数
- 最容易理解的算法了，在看不懂真的没救了

>重点，该解法并没有符合解题标准，请酌情观看，
>在此只是提供一种思路



```
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums = new int[nums1.length + nums2.length];
        int zw = nums.length / 2;
        for (int i = 0;i < nums.length; i++){
            if (i < nums1.length) nums[i] = nums1[i];
            else nums[i] = nums2[i-nums1.length];
        }
        Arrays.sort(nums);
        if (nums.length % 2 == 0){
            return (double)(nums[zw]+nums[zw-1])/2;
        }else {
            return (double)nums[zw];
        }
    }
```
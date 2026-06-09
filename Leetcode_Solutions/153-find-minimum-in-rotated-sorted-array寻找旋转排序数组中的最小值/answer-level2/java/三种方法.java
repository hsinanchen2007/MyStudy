三种方法，逐步优化

``` java
//第一种方法，时间复杂度o(nlogn)
class Solution {
    public int findMin(int[] nums) {
        if(nums == null)
            return 0;
        Arrays.sort(nums);
        return nums[0];
    }
}

// 第二种方法，时间复杂度o(n)
class Solution {
    public int findMin(int []nums) {
        if(nums == null)
            return 0;
        int min = nums[0];
        for(int num : nums){
            if(num < min)
                min = num;
        }
        return min;
    } 
}

//第三种方法,二分查找,时间复杂度o(n)
class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] > nums[right])
                left = mid;
            else
                right = mid;
        }
        return nums[left];
    }
}

```

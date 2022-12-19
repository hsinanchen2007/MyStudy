虽然排序需要O(nlog(n))，但是提交后比O(n)的双set法效率快很多。
```java
class Solution {
    public int findPairs(int[] nums, int k) {
        if(k < 0)
            return 0;
        Arrays.sort(nums);
        int count = 0;
        int start = 0;
        int after = 0;
        while(start < nums.length && after < nums.length){
            while(after < nums.length && nums[after] < nums[start] + k)
                after ++;
            if(after == start)
                after ++;
            if(after == nums.length)
                break;
            if(nums[after] == nums[start] + k)
                count ++;
            while(start < nums.length-1 && nums[start+1]==nums[start])
                start ++;
            start++;
        }
        return count;
    }
}
```
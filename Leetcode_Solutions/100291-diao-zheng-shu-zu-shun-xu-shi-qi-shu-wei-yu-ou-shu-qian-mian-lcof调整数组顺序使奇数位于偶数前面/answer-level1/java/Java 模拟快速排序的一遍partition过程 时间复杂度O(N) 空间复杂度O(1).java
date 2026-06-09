```java
//模拟一遍partition的过程, pivot是奇数; 时间复杂度O(N), 空间复杂度O(1)
class Solution {
    public int[] exchange(int[] nums) {
        //input check 
        if(nums==null || nums.length<2)
            return nums;
        int n=nums.length, small = -1, big=n, p=0;
        while(p<big){
            if(nums[p]%2==1)
                swap(nums, ++small, p++);
            else
                swap(nums, --big, p);
        }
        return nums;
    }
    private void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
```
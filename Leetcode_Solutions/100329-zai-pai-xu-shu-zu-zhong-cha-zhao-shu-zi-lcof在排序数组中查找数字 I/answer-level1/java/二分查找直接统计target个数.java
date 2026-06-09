```java
class Solution {
    private int count;
    public int search(int[] nums, int target) {
        count = 0;
        binarySearch(nums, target, 0, nums.length - 1);
        return count;
    }

    private void binarySearch(int[] nums, int target, int start, int end){
        if(start > end)return;
        int mid = (start+end)/2;
        if(nums[mid] == target){
            count++;
            binarySearch(nums, target, mid+1, end);
            binarySearch(nums, target,start, mid-1);
        }else if(nums[mid] < target){
            binarySearch(nums, target, mid+1, end);
        }else{
            binarySearch(nums, target,start, mid-1);
        }

    }   
}
```
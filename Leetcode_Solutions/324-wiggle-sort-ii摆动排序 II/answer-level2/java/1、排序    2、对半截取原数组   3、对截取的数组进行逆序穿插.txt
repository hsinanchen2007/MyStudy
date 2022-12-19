```
class Solution {
    public void wiggleSort(int[] nums) {
        if(nums == null || nums.length < 2)
            return;
        Arrays.sort(nums);
        int len = nums.length;
        int start1 = ((len&1) == 0) ? ((len>>1)-1) : (len>>1);
        int[] nums1 = Arrays.copyOfRange(nums,0,start1+1);
        int[] nums2 = Arrays.copyOfRange(nums,start1+1,len);
        int start2 = len-start1-2;
        int index =  0;
        while(start1 >= 0 && start2 >= 0){
            nums[index++] = nums1[start1--];
            nums[index++] = nums2[start2--];
        }
        if((len&1) == 1)
            nums[index] = nums1[0];
    }
}
```

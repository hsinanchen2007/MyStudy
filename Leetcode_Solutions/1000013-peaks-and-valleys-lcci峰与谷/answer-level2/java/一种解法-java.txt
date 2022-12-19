class Solution {
    public void wiggleSort(int[] nums) {
        if(nums.length<3)return;
        Arrays.sort(nums);
      int middle=nums.length/2;
        int[] valleys=Arrays.copyOf(nums,middle);
        for(int i=0;i<middle;i++){
            nums[2*i]=nums[middle+i];
            nums[2*i+1]=valleys[i];
        }
        
    }
}
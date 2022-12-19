```
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums.length==1) return nums;
        int lo = 0;
        int hi = nums.length-1;
        quickSort(lo,hi,nums);
        return nums;
    }
    private void quickSort(int lo,int hi,int[] nums){
        if(lo>=hi) return;    //如果尾指针低于或等于头指针，证明排序完成，直接返回
        int k = random(lo,hi); //随机取出数组中一个数，作为基准值，与最后的元素交换
        swap(nums,k,hi);
        int index = lo; //慢指针
        for(int i=lo;i<hi;i++){ //快指针
            if(nums[i]<nums[hi]){
                swap(nums,i,index);
                index++;
            }
        }
        swap(nums,index,hi);
        quickSort(lo,index-1,nums); //排左
        quickSort(index+1,hi,nums); //排右
    }
    private void swap(int[] nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    private int random(int x,int y){
        Random randomUtil = new Random();
        return x+randomUtil.nextInt(y-x); //取出[x,y)中的随机数，注意是左开右闭
    }
}
```
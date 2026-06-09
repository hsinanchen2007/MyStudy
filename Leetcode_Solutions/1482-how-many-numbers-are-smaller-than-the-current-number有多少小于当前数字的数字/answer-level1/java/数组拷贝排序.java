*斜体*# 标题
先把数组拷贝一份
将拷贝数组排序
将原数组元素的值改变为
“在拷贝数组中该元素的位置”
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int num = nums.length;
        int[] arr=new int[num];
        System.arraycopy(nums,0,arr,0,num);
        Arrays.sort(arr);
        for(int i=0;i<num;i++){
            int z=getIndex(arr,nums[i]);
            nums[i]=z;
        }
        return nums;
    }
    public int getIndex(int[] arr, int value) {        
        for (int i = 0; i < arr.length; i++) {   
            if (arr[i] == value) {            
                 return i;        
            }      
        }       
        return -1;
    }

}
```
class Solution {
    public int[] sortArray(int[] nums) {
        int[] arr=new int[100001];
        for(int num:nums){
            arr[num+50000]++;
        }
        int i=0;
        for(int j=0;j<100001;j++){
            if(arr[j]>0){
                while(arr[j]-->0){
                    nums[i++]=j-50000;
                }
            }
        }
        return nums;
    }
}
```

数据量不大，直接上代码
```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] arr=new int[101];
        for(int num:nums){
            arr[num]++;
        }
        int[] res=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums[i];j++){
                res[i]+=arr[j];
            }
        }
        return res;
    }
}
```

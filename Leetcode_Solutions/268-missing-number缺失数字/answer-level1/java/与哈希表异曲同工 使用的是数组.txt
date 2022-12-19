```
class Solution {
    public int missingNumber(int[] nums) {
        int a[] = new int[nums.length+1];
        for(int i =0;i<nums.length;i++){
            a[nums[i]] = 1;
        }
        for(int i = 0;i<a.length;i++){
            if(a[i]==0){
                return i;
            }
        }
        return -1;
    }
}
```

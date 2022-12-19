及简做法：
```
class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        int min=1;
        Arrays.sort(nums);
        int i=0;
        while(i<len){
            if(nums[i]==min){
                min+=1;
            }
            i++;
        }
        return min;
    }
}
```

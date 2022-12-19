```
class Solution {
    public int findNumbers(int[] nums) {
        int count=0;
        for(int i=0;i<nums.length;++i){
            if((nums[i]>=10&&nums[i]<100)||(nums[i]>=1000&&nums[i]<10000))
                count++;
        }
        return count;        
    }
}
```

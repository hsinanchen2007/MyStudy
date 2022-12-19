```java []
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length <= 1) return nums.length;
        int i = 1, j=1;
        int count = 1;
        int N = nums.length;
        while(j < nums.length){
            if(nums[j] != nums[j-1]){
                count = 1;
                nums[i] = nums[j];
                i++;
                j++;
            }
            else if(nums[j] == nums[j-1] ){
                count++;
                if(count > 2){
                    j++;
                    N--;
                    continue;
                }
                nums[i] = nums[j];
                i++;
                j++;
            }
        } 
        return N;
    }
}
```




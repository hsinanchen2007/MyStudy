```
class Solution {
    public int arrayNesting(int[] nums) {
        int max =0;
        for(int i =0; i< nums.length; i++){
            int count = 1;
            while(nums[i]!=i){
                swap(nums, nums[i], i);
                count++;
            }
            max = Math.max(max, count);
        }
        return max;
    }
    private void swap(int[] nums, int lo, int hi){
        int temp = nums[lo];
        nums[lo] = nums[hi];
        nums[hi] = temp;
    }
}
```
![image.png](https://pic.leetcode-cn.com/98dcda07700e916dfb0d460917b9a7f502b49b34533886249de60db53ba2b40f-image.png)


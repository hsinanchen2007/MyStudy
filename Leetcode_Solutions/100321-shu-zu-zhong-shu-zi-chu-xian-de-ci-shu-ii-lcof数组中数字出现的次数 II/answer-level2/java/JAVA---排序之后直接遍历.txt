![1a20dad6f6d676449152e41d236f869.png](https://pic.leetcode-cn.com/89b2aa659a6da88c818f2eff0d817a109a1d199598e27994ea64a8f54045cb8b-1a20dad6f6d676449152e41d236f869.png)

```
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        for(int i = 1;i<nums.length-1;i++){
            if(nums[i-1] != nums[i] && nums[i+1] != nums[i])
                return nums[i];
            else if(nums[nums.length-1] != nums[nums.length-2]){
                return nums[nums.length-1];
            }else if(nums[0] != nums[1])
                return nums[0];
        }
        return -1;
    }
}
```

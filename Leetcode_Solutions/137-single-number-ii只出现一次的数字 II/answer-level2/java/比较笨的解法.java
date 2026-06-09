先对原数组之中的元素进行排序，这样可以将大小相等的所有数字认为组合成一个一个的“块”。
由于题中说明只会有 1 个出现一次的数字，从而只要 nums[i] != nums[i - 1] 并且 nums[i] != nums[i + 1] 即可
为了防止数组越界，将数组的首尾进行特殊判断。
对于数组中仅有一个数字的情况，只需要 res = nums[0] 即可满足题意

```
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        if(nums.length == 1){
            res = nums[0];
        }
        else{
            for(int i = 1;i < nums.length - 1;i++){
                if((nums[i] != nums[i - 1]) && (nums[i] != nums[i + 1]))
                    res = nums[i];
                else continue;
            }
            if(res == 0){
                if(nums[0] != nums[1])
                    res = nums[0];
                else if(nums[nums.length - 1] != nums[nums.length - 2])
                    res = nums[nums.length - 1];
                else res = 0;
            }
        }
        return res;
    }
}
```

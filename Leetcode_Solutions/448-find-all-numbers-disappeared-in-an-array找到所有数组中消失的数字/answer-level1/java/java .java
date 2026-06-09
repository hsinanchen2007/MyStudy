[更多leetcode题解参考此处](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)
```
public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length ; i++) {
            while (nums[i] != nums[nums[i]-1]){
                swap(nums,i,nums[i]-1);
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if(nums[i] != i+1){
                list.add(i+1);
            }
        }
        return list;

    }

    private void swap(int[] nums, int i, int j){
        nums[i] = nums[j] + nums[i];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
    }
```

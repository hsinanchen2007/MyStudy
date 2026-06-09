```
    public int findRepeatNumber(int[] nums) {
        //<0代表那个位置的数已经访问过 到最后如果还没返回 那就是0重复了
        for (int i = 0; i < nums.length ; i++) {
            int index = Math.abs(nums[i]);
            if (nums[index]<0)
                return index;
            nums[index] *= (-1) ;
        }
        return 0;
    }
```

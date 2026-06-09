
直接加加减减即可，防止n*(n+1) 溢出
``` Java
    public int missingNumber(int[] nums) {
        int ans = nums.length;
        for (int i = 0; i < nums.length; i++){
            ans = ans + i - nums[i];
        }
        return ans;
    }
```

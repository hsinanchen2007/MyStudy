x,y,z三个数只有两种变换情况
1、x<=z 例如[1,4,2]或[2,4,2]，令y=z就可以
2、x>z 例如[3,4,2] 令z=y就可以
这两种情况是或的关系且只能够变换一次
```
class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length == 1) return true;
        for(int i = 0; i < nums.length - 1; i++) {
            if(nums[i] > nums[i+1]) {
                int temp = nums[i];
                nums[i] = nums[i+1];
                boolean a = isIncrese(nums);
                nums[i] = temp;
                nums[i+1] = temp;
                boolean b = isIncrese(nums);
                return a||b;
            }
        }
        return true;
    }
    private boolean isIncrese(int[] nums) {
        for(int i = 0; i < nums.length-1; i++) {
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
}
```

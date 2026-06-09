```

/**
 * @program: leetcode
 * @description:
 * @author: Mr.Ni
 * @create: 2020-01-26 14:53
 **/

public class 非递减数列 {
    //4,2,3
    public boolean checkPossibility(int[] nums) {
        if (nums.length < 2) {
            return true;
        }
        boolean flag = false;
        if (nums[0] > nums[1]) {
            flag = true;
            nums[0] = nums[1];
        }
        for (int i = 1; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1] && !flag) {
                if(nums[i-1]>nums[i+1]){
                    nums[i+1] = nums[i];
                }else {
                    nums[i] = nums[i+1];
                }
                flag = true;
            } else if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

```

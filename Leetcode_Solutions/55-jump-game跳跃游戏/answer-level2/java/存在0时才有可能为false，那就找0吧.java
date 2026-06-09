遍历数组，找0；
若不存在0，则一定为true；
如果存在0，就从0的位置往前找，看有没有能跳过去的，如果跳不过去，就为false。
```
public boolean canJump(int[] nums) {
    for (int i = 0; i < nums.length-1; i++) {
        if (nums[i] == 0) {
            if (i == 0) {
                return false;
            }
            int num = i - 1;
            while (num >= 0) {
                if (nums[num] > i-num){
                    break;
                }
                if (num == 0) {
                    return false;
                }
                num --;
            }
        }
    }
    return true;
}
```

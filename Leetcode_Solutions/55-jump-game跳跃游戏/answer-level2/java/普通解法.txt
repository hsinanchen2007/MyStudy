问题可以转换为：只需要能跳过值为0的台阶就一定能到达终点
从数组倒数第二个位置（倒数第一个位置已经到达终点了,不在考虑范围)向前搜索
每次遇到值为0的台阶就向前遍历，看能否跳过该台阶：前面的台阶的值 > 当前台阶下标 - 前面的台阶下标
```
public boolean canJump(int[] nums) {
    for(int i = nums.length - 2; i >= 0; i--){
        if(nums[i] == 0){
            boolean flag = false;
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] > i - j)
                    flag = true;
            }
            if(!flag)
                return false;
        }
    }
    return true;
}
```
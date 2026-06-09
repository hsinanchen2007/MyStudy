从后往前，我们只需要确定前面的点能有一种方法到目前的点，即可扔掉这个点，继而去判断能到这个点的前面那个点的到达情况，往复能走到最开始说明是条通路。
```
public boolean canJump(int[] nums) {
        int point = 0;
        if(nums.length == 0 || nums.length == 1) return true;
        else {
            point = nums.length-1;
            for(int i = nums.length-2;i >= 0;i --){
                if(nums[i]>=point-i){
                    point = i;
                }
            }
        }
        if(point == 0)
            return true;
        else return false;
    }
```
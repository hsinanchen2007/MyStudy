```
class Solution {
    public int removeDuplicates(int[] nums) {
        boolean hasTwo = false;
        int index = 0;
        for(int i = 1; i < nums.length; i++){
            if(!hasTwo && nums[i] == nums[i-1]){
                //暂时没有两个同样的数字
                //加入另一个同样的数字
                //那么现在就已经有两个同样的数字了
                nums[++index] = nums[i];
                hasTwo = true;
            } else if(hasTwo && nums[i] == nums[i-1]){
                // 已经有两个同样的数字了 第三个相同的数字
                // 也不能再加进来
                continue;
            } else {
                // 遇见了一个没见过的新数
                hasTwo = false;
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
}
```
之前加了一个：
```
        if(nums == null || nums.length < 1){
            return -1;
        }
```
就一直在[]的情况下执行出错，有人知道为什么吗。。。感觉这就是很标准的一种处理空数组的方式。。
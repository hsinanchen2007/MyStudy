# 思路：
1.nums中，i指针用于存放非零元素
2.j指针用于遍历寻找非零元素
（注：j指针找到一个非零元素后，方法nums[i]的位置，i++，用于下一个j指针找到的非零元素）
3.j指针遍历完后，最后nums数组还有空位置，存放0即可

# 代码如下：
```
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0;  
        for(int j = 0; j < nums.length; j++){
            if(nums[j] != 0){
                if(i != j){
                    nums[i] = nums[j];
                }
                i ++;
            }
        }
        for(; i < nums.length; i++){
            nums[i] = 0;
        }
    }
}
```


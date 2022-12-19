[leetcode376](https://leetcode-cn.com/problems/wiggle-subsequence/)

借用通信里面的上升沿和下降沿的概念：

* 若`nums[i]-nums[i-1]>0`又上一次产生了下降沿，那么本次就产生一次上升沿。
* 若`nums[i]-nums[i-1]<0`又上一次产生了上升沿，那么本次就产生一次下降沿。
* 最终结果为上升沿和下降沿之和在加一；

当然还有一些细节问题：

* 如果中间出现了`nums[i]-nums[i-1]=0`怎么办？直接不处理，相当于在原数组中将这些相等的直接事先删除了。
* 初始的状态确定：
  1. 从开头开始先找到第一个上升或者下降沿，然后在开始处理。
  2. 初始定义为`turn=0`表示既不是上升，也不是下降沿。

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length < 2) return nums.length;
        int turn = 0;
        int count = 0;
        for(int i =1;i<nums.length;i++){
            if( (turn == 0 || turn ==-1) && nums[i]-nums[i-1]>0){
                turn = 1;
                count++;
            }else if((turn == 0 || turn == 1) && nums[i]-nums[i-1]<0){
                turn = -1;
                count++;
            }                      
        }
        return count+1;

    }
}
```




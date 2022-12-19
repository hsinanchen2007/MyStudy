### 解题思路
在自己的范围允许内，跳到范围的最大值，即我每走一步，看这范围内的一步，谁离终点最近，谁就是我要跳到的地方
最后跳的时候别忘记最后一跳+1

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        int i=0;
        int jump_times = 0;
        while(i<nums.length-1){
            int scope = nums[i];
            int local_min_distance = Integer.MAX_VALUE;
            int currentIndex = 0;
            // 最后一步，距离已经超过终点就是他了
            if(nums[i]>=(nums.length-1-i)){
                jump_times++;
                break;
            }
            // 从当前节点够得着的范围内每一步
            // 每一步，谁离终点最近，谁就是要找的那个节点
            for(int j=1;j<=scope;j++){
                // 如果跳，跳到第几步了
                int step = nums[i+j];
                // 距离结尾的距离
                int distance = nums.length-1-i-j;
                int leap_length = Math.abs(step-distance);
                // System.out.println("元素脚标i="+i+",值为num["+i+"]="+nums[i]+",范围scope="+scope+",当前范围j="+j+",num["+i+"+"+j+"]="+step+",距离distance="+distance+",飞跃差leap_len="+leap_length);
                if(step >= distance){
                    // 一步到位
                    return jump_times+=2;
                }else{
                    if(leap_length<=local_min_distance){
                        local_min_distance = leap_length;
                        currentIndex = i+j;
                    }
                }
            }
            i = currentIndex;
            jump_times++;
        }
        return jump_times;
    }
}
```
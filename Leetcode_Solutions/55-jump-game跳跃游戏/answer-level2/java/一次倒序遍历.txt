    先贴代码：
    
```java []
class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length-2;//从倒数第二个元素开始遍历
        while (len >= 0) {//外层循环，主循环
            if (nums[len] ==0){//当遇到为0的元素的时候进入if
                int s=len; //s记录当前0出现的位置
                while (s - len >= nums[len]) {//内层循环，副循环，如果s与当前位置的差≥该位置的数
                                            //也就是说从该点跳，并不能跳过0出现的位置
                    len--;//继续往下走
                    if (len < 0) {//当len小于0的时候，也就是说内层循环完了都没能找到一个点，
                                //从那个点跳可以跳过0出现的位置，也就是说那个0是避不开的
                        return false;//此时返回false
                    }
                }
            }
            len--;//内层循环结束，也就是说找到了一个点从那个点跳可以避开上个0，继续往前寻找下个0
        }
        return true;//while结束，说明从上一个可以避开的0开始没有0了。返回true
    }
}
```
    
        

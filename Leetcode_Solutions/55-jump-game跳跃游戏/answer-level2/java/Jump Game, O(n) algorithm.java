*在评论区发现了一些很好的解法， 在此分享一下我的解法，自我感觉甚是巧妙，减少了index的处理。*
击败Java 100%， 耗时1ms
**【False的罪魁祸首就是0！】**
## 解题思路
```
    - 初始化zeroCount为0，从右往左（从倒数第二个开始）遍历数组，
        - 遇到0则zeroCount++；
        - 否则判断nums[i]是否大于zeroCount；
            - 若大于，则置zeroCount为0，继续遍历；
            - 否则zeroCount++；
    - 遍历结束后若zeroCount>0，说明nums中某个0不可避免，则返回false；
    - 否则返回true。
```

## 代码
```
class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if(n==0) return false;
        if(n==1) return true;

        int zeroCount = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]==0) zeroCount++;
            else{
                if(nums[i]>zeroCount) zeroCount=0;
                else zeroCount++;
            }
        }
        if(zeroCount>0) return false;
        else return true;
    }
}
```

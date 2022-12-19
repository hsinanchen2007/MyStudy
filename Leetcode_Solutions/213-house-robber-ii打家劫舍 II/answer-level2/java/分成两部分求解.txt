### 解题思路
给rob方法添加两个参数，start和end,一个数组范围为[0-len-2],另一个数组范围为[1,len-1]。
求两个数组情况下的最大值。

### 代码

```java
class Solution {

    public int rob(int[] nums) {
        int len=nums.length;
        if(len == 0) return 0;
        if(len == 1) return nums[0];
       return Math.max(myRob(nums,0,len-2),myRob(nums,1,len-1));
    }

    public int myRob(int[] nums,int start,int end){
         int preMax=0;
        int curMax=0;
        for(int i=start;i<=end;i++){
            int temp=curMax;
            curMax=Math.max(preMax+nums[i],curMax);//当前值+i-2个值，与i-1个值
            preMax=temp;
        }
    return curMax;
    }

}
```
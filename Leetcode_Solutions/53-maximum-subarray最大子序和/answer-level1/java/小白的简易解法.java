### 解题思路


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int i=0;
        int total=0;
        int ans=nums[0];//如何解决输入是负数的问题，最好的办法就是拿数组中的数进行初始话。
        while(i<nums.length){
            //如果大于0就是sum加上下一个元素就是递增，如果小于0则递减
            //如果出现递减的情况，则没有必要加入，将其作为新一个子串的开始
            //继续运行
            if(total>=0){
                total+=nums[i];
            }else{
                total=nums[i];
            }
//这里这个比较大小的地方可以轻松的完成比较。
            ans=Math.max(ans,total);
            i++;
        }
        return ans;
    }
}
```
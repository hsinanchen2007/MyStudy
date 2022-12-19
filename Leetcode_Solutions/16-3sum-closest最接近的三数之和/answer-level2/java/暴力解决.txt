### 解题思路
刚开始想到了，优先级队列（小根堆）解决的，然后弹出最顶端，优先级队列存一个Pair<Math.diff(diff),-nums[i]-nums[j]-nums[k]>,这样就把最小的值放到了堆得顶端，但是这样浪费空间，用堆得目的一般是返回第K个最小或者最大元素。

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int min = Integer.MAX_VALUE;
        int minTarget = 0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                for(int k=j+1;k<nums.length;k++){
                    int diff = target-nums[i]-nums[j]-nums[k];
                    if(Math.abs(diff) < min){
                        min = Math.abs(diff);
                        minTarget = nums[i]+nums[j]+nums[k];
                    }
                }
            }
        }
        return minTarget;
    }
}
```
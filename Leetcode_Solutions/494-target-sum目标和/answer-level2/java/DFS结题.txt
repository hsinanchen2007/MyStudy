### 解题思路
此处撰写解题思路
使用DFS方法，也就是把所有的可能性弄出来
### 代码

```java
class Solution {
   Integer sum=0;
    public int findTargetSumWays(int[] nums, int S) {
        backTracing(nums,S,0,0);
        return sum;
    }

    public void backTracing(int[] nums,int S,int index,int cur){
        if(index==nums.length){
            if(cur==S){
                sum++;
            }
            return;
        }
        cur=cur+nums[index];
        backTracing(nums,S,index+1,cur);
        cur=cur-2*nums[index];
        backTracing(nums,S,index+1,cur);

    }
}
```
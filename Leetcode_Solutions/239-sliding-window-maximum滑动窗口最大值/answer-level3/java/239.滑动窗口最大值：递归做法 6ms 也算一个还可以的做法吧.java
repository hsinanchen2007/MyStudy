### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length==0)return new int[0];
        int[] ret = new int[nums.length-k+1];
        solve(nums,ret,0,nums.length-1,k);
        return ret;
    }
    /**
    nums和ret不用说
    p和r尾nums数组的下标，两边都取到
    递归函数的目标：当solve退出时,ret[p...r-k+1]得到确定
    原理：
    如果一个数组的最大值在数组的max处，那么ret[max-k+1...,max]得到确定
    example:nums=[1,2,3,7,6,5,4] k= 3
    nums[max]=nums[3]=7
    ret[1]=ret[2]=ret[3]=7
    
    但是边界上会有一些细节
    */
    private void solve(int[] nums,int[] ret,int p,int r,int k){
        if(p>r)return;
        int max = p;
        for(int i=p;i<=r;i++){
            if(nums[i]>nums[max]){
                max = i;
            }
        }
        //在区间[max-k+1...,max]和[p...r-k+1]之间取交集[down,up]
        int down = Math.max(p,max-k+1);
        int up = Math.min(max,r-k+1);
        //ret[down,...,up]是真正可以确定的
        if(up<down)return;//没有需要确定的
        for(int i=down;i<=up;i++)ret[i]=nums[max];

        solve(nums,ret,p,max-1,k);
        solve(nums,ret,max+1,r,k);
    }
}
```
### 解题思路
1、假设当前索引为i,imin表示以i-1为终点的最小连续子乘积，imax表示截止以i-1为终点的最大连续子乘积
2、那么i时刻的imin = Math.min(imin*nums[i],nums[i]) 
             imax = Math.max(imax*nums[i],nums[i])
    注意当nums[i]<0的时候，需要交换imin,imax
    最后结果就是Math.max(max,imax)        

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
       int max = Integer.MIN_VALUE;
        int imin = 1;
        int imax = 1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<0){
                int tmp = imin;
                imin = imax;
                imax = tmp;
            }
            imin = Math.min(imin*nums[i],nums[i]);
            imax = Math.max(imax*nums[i],nums[i]);
            max = Math.max(imax,max);
        }
        return max;
    }
}
```
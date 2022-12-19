### 解题思路
![QQ截图20200317165857.png](https://pic.leetcode-cn.com/3170ecb95238cb77e0461763111ea32b67646c166d761e2452e8daefdc1438f8-QQ%E6%88%AA%E5%9B%BE20200317165857.png)

https://leetcode-cn.com/problems/maximum-subarray/solution/yong-dong-tai-gui-hua-shi-jian-fu-za-du-shi-onyong/
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
         int sum=nums[0],b=nums[0];
        for(int j=1;j<nums.length;j++){
            if(b>0) {b+=nums[j];}
            else {b=nums[j];}
            if(b>sum) {sum=b;}
        }
        return sum;

    }
}
```
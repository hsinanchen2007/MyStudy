### 解题思路
如果有连续两个上升段，那就是true
观察false情况下的图像，也就是找出每个上升段，它的low小于上一段low并且high小于上一段的high，那就说明
目前为止情况是false，没有出现true的情况，一旦有大于，那就true
如图false的情况一定是这样的图像
![无标题.png](https://pic.leetcode-cn.com/ac161140f800e339bbfef85c2a0ff76a3007cfc70aa1b9157d97ca0bb04aa142-%E6%97%A0%E6%A0%87%E9%A2%98.png)
```

### 代码

```java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int i=0;
        int low=Integer.MAX_VALUE,high=low;
        int flag = 0; //0说明上一个i和i+1不是递增的，用来判断是不是连续三个递增的
        for(i=0;i<nums.length-1;i++){
            if(nums[i]<nums[i+1]){
                if(flag==1) return true;
                if(nums[i]>low||nums[i+1]>high) return true;
                low = nums[i];
                high = nums[i+1];
                flag=1; 
            }
            else flag=0;
        }
        return false;
    }
}
```
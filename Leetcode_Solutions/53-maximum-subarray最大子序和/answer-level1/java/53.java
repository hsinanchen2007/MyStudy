### 解题思路
![最大子序和-53.png](https://pic.leetcode-cn.com/bc9f8bbf2b66fe16514ab9fc97918a7e72e9363bac137f3a9e9c40b2eba32ad4-%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C-53.png)
一边求和一边比较最大值；若某次求和<0，将和值重新置0；若某次求和值大于当前最大值，将此次和值置为最大值。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
       int Max = nums[0],sum = 0;
       for(int i = 0; i < nums.length; i++){
           sum += nums[i];
           if(sum > Max){
               Max = sum;

           }
           if(sum < 0) sum = 0;
       }
       return Max;

    }
}
```
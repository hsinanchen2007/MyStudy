### 解题思路
Java小白：

首先把nums[0]赋值给ans；然后用增强for循环nums，其中nums大于0对增加有增益效果，反之对增加有负效果，如果sum大于0，sum等于前面的sum和加上num，否则直接把num赋值给sum。
最后把ans与sum的大值赋给ans，直到循环完成，最后的ans就是数组连续子序列和的最大值

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        int sum = 0;
        for(int num : nums){
            if(sum > 0){
                sum += num;
            }else{
                sum = num;
            }
            ans = Math.max(ans,sum);
        }
        return ans;
    }
}
```
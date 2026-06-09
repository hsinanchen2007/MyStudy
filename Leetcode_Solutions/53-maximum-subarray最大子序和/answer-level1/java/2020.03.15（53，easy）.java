### 解题思路
本题使用**动态规划**解决问题

通过一遍遍历数组，若之前遍历过的元素之和sum为正数，就可以加上当前的元素num，否则就更新sum指向当前的num

最终得到的结果ans再和sum比较取最大值即可。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        int sum = 0;
        for(int num : nums){
            if(sum > 0){//如果有增益，就加上当前的num
                sum += num;
            }else{//如果sum不是正数，就更新sum指向当前num
                sum = num;
            }
            ans = Math.max(ans,sum);
        }
        return ans;
    }
}
```
### 解题思路
**思路：**
因为，中心索引左边的元素和 leftSum 等于中心索引右边的元素和 rightSum。
所以，leftSum + leftSum + nums[i] = Sum (所有元素的和)。
我们把 i 看作自变量，把 leftSum 看作因变量，可以得到方程：2 * leftSum = Sum - nums[i];
当 i 为中心索引时，此方程成立。
所以我们遍历 i ，当方程成立时 i 就是中心索引。

**代码：**
```java
class Solution {
    public int pivotIndex(int[] nums) {
        int length = nums.length;
        int sum = 0, leftSum = 0;

        // 获取数组元素总和
        for (int num: nums) sum += num;
        
        // 遍历自变量
        for (int i = 0; i < length; i++){
            if (leftSum*2 == sum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
}
```

博客：www.lxiaocode.com
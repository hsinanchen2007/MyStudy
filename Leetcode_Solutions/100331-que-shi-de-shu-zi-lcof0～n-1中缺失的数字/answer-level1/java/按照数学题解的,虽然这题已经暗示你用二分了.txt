### 解题思路
n-1个说明原来应该有n个数字,求和然后想减就是那个不存在的数字

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
    int sum=0;
    for(int i=0;i<nums.length;i++){
        sum+=nums[i];
    }
    int target=(0+nums.length)*(nums.length+1)/2;
    return target-sum;
    }
}
```
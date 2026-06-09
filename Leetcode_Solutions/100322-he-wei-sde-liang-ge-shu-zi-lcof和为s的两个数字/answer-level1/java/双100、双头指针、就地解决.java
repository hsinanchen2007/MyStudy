### 解题思路
我发现很多时候就地解决会比结束循环体再处理要快一些, 就做得极端了一些

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int head=0,tail=nums.length-1;
        while(head<tail){
            int sum=nums[head]+nums[tail];
            if(sum==target)return new int[]{nums[head],nums[tail]};
            else if(sum>target) tail--;
            else head++;
        }
        return null;
    }
}
```
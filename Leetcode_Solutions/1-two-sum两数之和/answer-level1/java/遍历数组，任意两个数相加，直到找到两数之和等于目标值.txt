### 解题思路
遍历数组中任意两个数，进行求和，发现和等于目标值的两个数，就停止并返回。
如：
先取数组第一个值，将第一个值挨个与后面每个值相加，如果找到和等于目标值了的，就返回。如果都没有找到，则取数组第二值，然后重复上面步骤。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = {0, 1};
        for(int i = 0;i<nums.length-1;i++)
        {
            for(int j = i+1;j<nums.length;j++)
            {
                if( target == (nums[i]+nums[j]))
                {
                    result[0] = i;
                    result[1]=j;
                    return result;
                }
            }
        }
    return result;
    }
}
```
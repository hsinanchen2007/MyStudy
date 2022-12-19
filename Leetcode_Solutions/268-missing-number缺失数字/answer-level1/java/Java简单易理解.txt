### 解题思路
先对数组进行排序，之后遍历，比较值与下标索引是否相同，如果不相同则返回该值（返回值或索引效果相同），如果遍历后没有找到值与索引不相同的，那么说明缺失的是最后一个数字（例如：数组为0,1,2,3,4,5           数组长度是6，题目中的n个数也就是0到6之间，少了一个6）

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0;i < nums.length;i++){
            if (nums[i] != i){
                return i;
            }
        }
        return nums.length;
    }
}
```
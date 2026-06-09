### 解题思路
解决思路是空间换时间。创建大数组，然后讲数组里面有的数字置1。然后遍历数组，没有置1的就是缺失的了。

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int[] array = new int[nums.length+1];

        for(int i = 0; i < nums.length; i++){
            array[nums[i]] = 1;
        }
        for(int i = 0; i < array.length; i++){
            if(array[i] != 1)
                return i;
        }
        return 0;
    }
}
```
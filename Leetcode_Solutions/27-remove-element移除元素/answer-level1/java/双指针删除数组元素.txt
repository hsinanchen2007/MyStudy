### 解题思路
双指针删除数组元素，将数组中非val值的数组元素赋值给数组头部

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        //定义双指针
        int i = 0;
        for(int j = 0; j<nums.length;j++)
            if(nums[j]!=val){
                nums[i++]=nums[j];
            }
        return i;

    }
}
```
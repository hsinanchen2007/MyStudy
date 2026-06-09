### 解题思路
使用一个position记录新数组的边界。遍历数组，若出现重复值，position不变，继续遍历；若出现不同值，则position+1，使用该不同值替换递增后position的值。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int position = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] != nums[position]){
                position++;
                nums[position] = nums[i];
            }
        }
        return position + 1;
    }
}
```
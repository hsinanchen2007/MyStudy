### 解题思路
哈哈 练排序呢

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        //直接选择排序
        for (int i = 0; i < nums.length - 1; i++) {
            //记录当前位的索引值 选择i位
            int temp = i;
            for (int j = i+1; j < nums.length; j++) {
                if (nums[j] <= nums[temp]) {
                    temp = j;
                }
            }
            //交换两个值
            if (i != temp) {
                int temp1 = nums[i];
                nums[i]   = nums[temp];
                nums[temp]= temp1;
            }

        }
    }
}
```
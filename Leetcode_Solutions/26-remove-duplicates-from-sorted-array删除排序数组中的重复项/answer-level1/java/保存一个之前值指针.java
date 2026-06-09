### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0) return 0;
        int index = 0;
        int pre = nums[0]; // 表示之前的值
        for (int i = 1; i < nums.length; i++) {
            if (pre != nums[i]) {   // 当前值和之前值不相同, 则需要进行加一覆盖
                nums[++index] = nums[i];
            }
            pre = nums[index]; // pre保存之前值, 当然可以不需要这一个变量
        }
        return index + 1;
    }
}
```
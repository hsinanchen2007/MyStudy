### 解题思路
此处撰写解题思路
1. 标记重复元素；
2. 向前移动非重复元素；
### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null) {
            return 0;
        }
        if(nums.length < 2) {
            return 1;
        }
        // 偏移量
        int offset = 0;
        int duplicateNum = nums[0];
        int countNum = 1;
        int temp = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(duplicateNum == nums[i]) {
                offset += 1;
                continue;
            } 
            // 重新记录重复元素
            duplicateNum = nums[i];
            countNum++;
            if(offset > 0) {
                temp = nums[i - offset];
                nums[i-offset] = nums[i];
                nums[i]= temp;
            }
        }
        return countNum;
    }
}
```
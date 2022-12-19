### 解题思路
1.遍历数组把非零元素（假设有k个）按顺序存入数组的0至k-1位置上；
2.把原数组剩余未新赋值部分(k到n-1位置上)全设置为0；

第一次写解题思路，多多包涵……

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }
        for (; index < nums.length; index++) {
            nums[index] = 0;
        }
    }
}
```
### 解题思路

双指针
先假设第一个元素是0，遍历数组找到不是0的元素，跟0元素的指针数据交换，交换后继续遍历，直至数组循环完成。


### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int zeroFlag = 0;//指向0元素
        for (int i=0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (zeroFlag != i) {
                nums[zeroFlag] =nums[i];//元素交换
                nums[i] = 0;
            }
             zeroFlag ++;
            } 
        }
    }
}
```

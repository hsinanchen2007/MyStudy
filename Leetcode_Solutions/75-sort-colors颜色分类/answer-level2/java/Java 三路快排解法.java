### 解题思路
利用三路快速排序思路

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int zeroPos = -1;   // [0, zeroPos]集合内元素全为0
        int twoPos = nums.length;   // [twoPos, nums.length-1]集合内元素全为2
        for (int i = 0; i < twoPos;) {
            if (nums[i] == 0) { // 遇到0则加入前方集合，与集合后第一个元素交换
                zeroPos++;
                nums[i] = nums[zeroPos];
                nums[zeroPos] = 0;
                i++;
            } else if (nums[i] == 1) {  // 遇到1则什么也不需做，直接遍历下一个
                i++;
            } else {    // nums[i] == 2     遇到2则加入后方集合，与集合前第一个元素交换
                twoPos--;
                nums[i] = nums[twoPos];
                nums[twoPos] = 2;
            }
        }
    }
}
```
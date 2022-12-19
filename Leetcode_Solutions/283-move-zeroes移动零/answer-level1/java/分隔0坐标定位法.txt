### 解题思路
此处撰写解题思路
1. 记录起始的0坐标位置
2. 遍历整个数组
3. 当发现当前的元素为非零元素，则将当前的元素保存到0坐标的起始位置
4. 然后将当前坐标标记为0
5. 但是，还存在一种情况，还没有找到0坐标，会导致数据被替换为0，所以2个元素进行数据替换，最安全。
6. 经过分析，时间复杂度为：O(n)
### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int splitIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                //把不为负的值替换到当前为0的位置
                int tmp = nums[splitIndex];
                nums[splitIndex] = nums[i];
                nums[i] = tmp;
                splitIndex++;
            }
        }

    }
}
```
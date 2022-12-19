### 解题思路
首先，缺失的最小整数一定小于等于数组长度length，所以数组中大于等于length的值和小于1的值都不影响最终结果。
第一次遍历：
将数组中值为length的位置，修改成0。（因为值为length和0对最终结果都无影响，后面需要用length这个值标记）
第二次遍历：
由于只能开辟常数空间存储，为了记录哪些数字出现过，只能利用题目中给出的数组nums来记录。
我们用下标 nums[a-1] = length来表示a这个数组出现过。这里面需要迭代的去写入值。
第三次遍历：
找出第一个没有被标记的下标，加一，即为结果。如果全部被标记，结果即为length + 1

三次遍历，由于第二次遍历每个位置只被写入一次，因此时间复杂度O(n),只使用了临时变量，空间复杂度O(1)；

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int length = nums.length;
        for (int i = 0; i < length; i++) {
            if (nums[i] == length + 1) {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < length; i++) {
            if (0 < nums[i] && nums[i] < length + 1) {
                int tag = nums[i];
                while (tag > 0 && tag < length + 1) {
                    int tmp = nums[tag - 1];
                    nums[tag - 1] = length + 1;
                    tag = tmp;
                }
            }
        }
        
        for (int i = 0; i < length; i++) {
            if (nums[i] != length + 1) {
                return i + 1;
            }
        }
        return length + 1;
    }
}
```
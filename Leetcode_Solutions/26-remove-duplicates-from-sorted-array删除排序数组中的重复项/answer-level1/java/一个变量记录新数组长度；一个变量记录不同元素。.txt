### 解题思路
1. 对于空数组, 直接返回0;
2. 那么就是非空数组, 至少存在一个元素;
    1. 默认从第二个元素, 开始判断上一个num中的值和当前值是否一致
    2. 相同：则直接continue；
    3. 不同则， 修改上一个不同元素之后的第一个位置数据；同时，修改num。
    4. 让num始终记录着第一次出现不同元素时的数据。newLength则记录上一个不同元素之后的位置。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int newLength = 1;
        int num =  nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == num) {
                continue;
            }

            nums[newLength++] = nums[i];
            num = nums[i];
        }

        return newLength;
    }
}
```
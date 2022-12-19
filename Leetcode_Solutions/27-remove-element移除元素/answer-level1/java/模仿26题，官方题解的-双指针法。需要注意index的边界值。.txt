### 解题思路
1. 若数据为空, 直接返回0;
2. 数据不为空，则主旨思想为"双指针法"。
    1. j从头至尾遍历，碰到等于val时，则使用数据末尾的非valval值替换。
    2. 当i<=j时, 说明数组已经遍历完成, 直接返回j即可。j之前的为非val的数据。
    3. 当j>=i时，推出循环时, 说明j之前的数据为非val的。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int i = nums.length - 1;
        int j = 0;
        for (; j <= i; j++) {
            if (nums[j] == val) {
                while (nums[i] == val) {
                    i--;

                    if (i < 0) {
                        return 0;
                    }
                }

                if (i <= j) {
                    return j;
                }

                nums[j] = nums[i];
                i--;
            }
        }

        return j;
    }
}
```
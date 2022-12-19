![图片.png](https://pic.leetcode-cn.com/50bd56795d1764128925f97bcd9fd153f925cd3dca711473071e6937536da4ce-%E5%9B%BE%E7%89%87.png)
——————————————————————————————————————————————————
1. 数组：`[………,a,b,c]`
2. 倒序比较
3. **前提：`a > b`**
    - 情形1：`a > c`  -----> `[………,b,b,c]` 元素 *a --> b*
    - 情形2：`a <=c`  -----> `[………,a,a,c]` 元素 *b --> a*(此情形可以只记录次数，不做改变)
4. *`b > c`的判定不用讲了吧 (原因: `c` 参与了`a、b`的赋值比较，并且记录了次数 )*

——————————————————————————————————————————————————
```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        if (nums.length < 3)
            return true;
        // 元素改变的次数
        int count = 0;

        // 倒序遍历
        for (int i = nums.length - 2; i >= 0; i--) {
            // 改变超过1次，结束循环
            if (count > 1)
                return false;
            if (nums[i] <= nums[i + 1])
                continue;

            // 改变元素

            // [3, 4, 2, 3] :此情形需要： 4,2,3 -->2,2,3，然后继续循环比较
            if (i + 2 < nums.length && nums[i] > nums[i + 2])
                nums[i] = nums[i + 1];

            // [2, 3, 3, 2, 4] ：此情形不需要改变值，只记录次数
            // nums[i + 1] = nums[i]; (3,2,4 --> 3,3,4)这个改变是没有意义的

            count++;
        }
        // 改变1次 或者 未改变
        return count < 2;
    }
}
```

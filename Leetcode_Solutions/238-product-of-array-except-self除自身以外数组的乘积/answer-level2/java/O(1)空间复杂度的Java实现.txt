### 解题思路
为了实现O(1)的空间复杂度，复用结果数组answer, 记录当前index左侧所有数值的乘积；
用一个变量r 记录当前节点的右侧所有值的乘积；
首先从左侧遍历，得到answer数组；
然后从右侧遍历，修改answer数组。

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int length = nums.length;
        if (length == 0) {
            return null;
        }
        int []answer = new int[length];

        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int r = nums[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            answer[i] = answer[i] * r;
            r = r * nums[i];
        }

        return answer;

    }
}
```
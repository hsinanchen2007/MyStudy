### 解题思路

最直白的想法是寻找并且统计“逆序对”，修改必定发生在逆序对周围。然后，再考虑无法修改为非递减数列的情况。

首先，逆序对数列大于 1 的时候必定无法修改。

其次，假设只有 1 个逆序对（如 `nums[i - 1] > nums[i]`），可能有两种修改方法，即：

- 减小 `nums[i - 1]`
- 增加 `nums[i]`

那么，不能修改的情况对应如下： 

- `nums[i - 2] > nums[i]`（注意 `nums[i]` 至少是第三个元素） 
- `nums[i - 1] > nums[i + 1]`（注意 `nums[i]` 至多是倒数第二个元素）

因为，只要有一种修改方案可行即可成功，所以上面的两个布尔条件要使用 **AND** 连接。

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int cnt = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] <= nums[i]) continue;
            cnt++;
            if (cnt > 1) return false;
            if (i > 1 && nums[i - 2] > nums[i] 
                && i < nums.length - 1 && nums[i - 1] > nums[i + 1])
                return false;
        }
        return true;
    }
}
```
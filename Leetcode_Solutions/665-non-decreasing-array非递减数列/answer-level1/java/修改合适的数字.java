1. 如果要满足非递减数列，那么就要在遇到**前一个数大于后一个数**这种情况时，修改一个数字；
2. 题目限制最多可以改变**一个元素**，那么我们只要记下**是否修改过**这个状态，然后在第二次修改的时候返回失败即可。
3. 修改有两种方式，根据不同的情况来分析应该如何修改
    - 第一种是修改 **当前数字（下标 i)** 的值为 **后一个数字（下标 i+1）** 的值
    - 第二种是修改 **后一个数字（下标 i+1）** 的值为 **当前数字（下标 i）** 的值

    - 当且仅当**当前数字**不是第一个，并且**后一个数字**的值小于**前一个数字**的值的时候，使用第二种
    - 其他情况使用第一种

```java
public boolean checkPossibility(int[] nums) {
    // 如果数组长度小于2直接返回True
    if (nums.length <= 2) {
        return true;
    }
    // 记录是否已经修改过
    boolean isChanged = false;
    for (int i = 0; i < nums.length - 1; i++) {
        // 前一个数大于后一个数时需要进行修改
        if (nums[i] > nums[i + 1]) {
            if (!isChanged) {
                // 实现修改数组的代码
                if (i > 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i + 1];
                }
                // 改变是否已经修改过的状态
                isChanged = true;
            } else {
                return false;
            }
        }
    }
    return true;
}
```




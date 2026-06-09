### 解题思路
    /*
     * 首先对数组进行排序，再计数数组中0的个数。因为0可以代表任何数，所以0可以填充顺子中缺少的数。
     * 如果数组为顺子，则数组中0的个数必然大于或等于数组中缺少的数。
     * 如果等于，则0直接填充即可；如果大于，表示0可以填充最后面的数。
     * 所以只需要计算排序好后的数组中缺少数的个数，在与0的个数比较即的结果。
     * */
### 代码

```cpp
bool isStraight(std::vector<int> &nums) {
    if (nums.empty() || nums.size() < 5) {
        return false;
    }

    // 将数组排序为升序
    std::sort(nums.begin(), nums.end());

    // 计数0的个数
    int isZero = 0;
    for (int n : nums) {
        if (n == 0) {
            isZero++;
        }
    }

    // 数组在缺少的数
    int isGap = 0;
    // 左边的数，从第一个不为0的数开始
    int left = isZero;
    // 右边的数
    int right = left + 1;
    while (right < nums.size()) {

        // 如果两个数相等，必然不是顺子
        if (nums[left] == nums[right]) {
            return false;
        }

        // 计算数组中缺少的数
        isGap += nums[right] - nums[left] - 1;

        left++;
        right++;
    }

    // 比较缺少的数与0的个数
    return isGap <= isZero;
}
```
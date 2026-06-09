#### 利用鸽巢原理解答，即“一个萝卜一个坑”：

首先依次判断每个元素 nums[i]，若它在 i+1 的位置上，说明处在了正确的位置，那么看下一个位置。

若下一个位置  nums[i] ！= i + 1，说明 nums[i] 放错了位置，它正确的位置应该是 nums[nums[i] - 1]。比如说 nums[0] = 4，那么 4 应该是 nums[nums[0] - 1] = nums[3] 这个值。这时应该将   nums[i] 和 nums[nums[i] - 1] 交换，但前提是这个坑还没有被占。所以在交换之前应该先判断两数是不是已经相等了，若已经相等了，说明已经有萝卜占了正确的坑了，现在的这个萝卜是重复的。

像上面这样交换完了之后，再次遍历一遍数组，遇到 nums[i] != i+1 的，就是重复的萝卜落在了没有萝卜的坑里。由于萝卜和坑是一一对应的，所以重复的萝卜指向的位置就是缺失的数字的坑啦~

```cpp
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    while (i < len) {
      if (nums[i] == i + 1) {
        i++;
      } else {
        if (nums[i] != nums[nums[i] - 1]) {
          std::swap(nums[i], nums[nums[i] - 1]);
        } else {
          i++;
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < len; i++) {
      if (nums[i] != i + 1) { ans.push_back(i + 1); }
    }
    return ans;
  }
};
```
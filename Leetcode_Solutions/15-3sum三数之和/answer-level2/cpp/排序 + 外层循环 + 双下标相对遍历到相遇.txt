### 解题思路
PS：好在题目的参数上没有给我加const，能让我预先排个序，后边的去重就方便了好多。

这个题目的思路其实很多人都有了，无非就是先排序，然后外层循环遍历到某个元素时（设为x），用两个指针或者下标，在x的右边数组剩余的部分里，去寻找另外两个数，使得他们相加能够等于-x。设置left从x的右边紧邻的元素准备往右走，right从数组尾部准备往左走（想想快排里的两个指针）。如果left + right > -x，那么left就往右走一个元素，使得left + right的值增大一点；如果left + right < -x，那么right就往左走一个元素，使得left + right的值减小一点。然后再比较left + right和-x。只要碰到left + right == x的，就加入结果集。终止条件是left与right相遇。

一个加速的技巧是，left和right在各自移动的过程中，只要碰到一样的连续元素（因为已经排好序了），执行判断遇到的首个元素后，就连续走过之后的那些。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int nums_size = nums.size();
        if (nums_size < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums_size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums_size - 1;
            int find = - nums[i];
            while (left < right) {
                if (nums[left] + nums[right] < find) {
                    while (nums[++ left] == nums[left - 1] && left < right) continue;
                } else if (nums[left] + nums[right] > find) {
                    while (nums[-- right] == nums[right + 1] && left < right) continue;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (nums[++left] == nums[left - 1] && left < right) continue;
                    while (nums[--right] == nums[right + 1] && left < right) continue;
                }
            }
        }

        return result;
    }
};
```
![微信图片_20191231144218.png](https://pic.leetcode-cn.com/a2a0adf7f6c202761e927183a26d5a2aba5165e58fa732f5d8fdfe56d972ec59-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191231144218.png)


效率不是很高，只打败了45%。

解题思路：整体是回溯法+剪枝。回溯法是通用做法，详见代码。
剪枝思路如下：
1）如果数组总和不能被k整除，则一定不能平分成k组；
2）如果数组里有值比平均值还大，则该数一定不能被放到分组里，无法平分；
3）数组提前排序，可以大幅增加递归时的命中概率。

```
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int maxVal = 0;
        for (auto &n : nums) {
            sum += n;
            maxVal = max(maxVal, n); // 第一次优化，找出最大值，如果大于平均值则一定失败
        }

        if (sum % k != 0 || maxVal > (sum / k)) return false;

        // 第二次优化，从大到小排序，增加分组选择的命中率
        sort(nums.begin(), nums.end(), [](int &a, int &b) { return a > b; });

        vector<bool> visit(nums.size(), false);

        return isValidSubset(nums, 0, 0, sum / k, visit);
    }

    bool isValidSubset(vector<int>& nums, int sum, int count, int averNum, vector<bool> &visit) {
        if (count == nums.size()) {
            // count代表已选中的数量，当所有的数字都已被选中，代表成功。
            // 因为前面已经去除了失败的条件，意味着只要所有数字都选中了，则一定成功
            return true;
        }

        // 选到一组等于平均值的，把当前组的sum清零继续往下找
        if (sum == averNum) {
            return isValidSubset(nums, 0, count, averNum, visit);
        }

        // 这里是回溯法，一般的套路。递归前操作，递归后还原。需要增加visit数组，防止数字被重复选中
        for (int i = 0; i < nums.size(); i++) {
            if (!visit[i] && sum + nums[i] <= averNum) {
                sum += nums[i];
                visit[i] = true;
                if (isValidSubset(nums, sum, count+1, averNum, visit)) return true;
                visit[i] = false;
                sum -= nums[i];
            }
        }

        // 所有情况已遍历了都不成功，返回失败
        return false;
    }
};
```

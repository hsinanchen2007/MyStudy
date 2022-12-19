一开始以为先排序之后，用贪心从大往小取就好，结果发现会有问题，比如[5,5,5,5,4,4,4,4,3,3,3,3]，会取到5，5，然后返回false。所以必须加上回溯。
思路：先求和得出边长是多少，如果求和之后不是4的倍数，那么可以直接返回false。
有了边长之后，我们再写一个方法，这个方法的作用是在没使用过的火柴里面找到长度总和等于边长的火柴。这个方法使用递归回溯来实现。就可以避免只使用贪心的错误。另外加入一些剪枝代码，加快速度。

```
class Solution {
public:
    bool findSum(vector<int>& nums, vector<bool>& visited, int s, int target) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        int lastTarget = -1;
        for (int j=s; j>=0; j--) {
            if (visited[j]) {
                continue;
            }
            int t = target - nums[j];
            if (lastTarget == t) { // 这个目标已经递归过了，直接跳过
                continue;
            }
            if (t < 0) {
                continue;
            }
            visited[j] = true;
            lastTarget = t;
            if (findSum(nums, visited, j-1, lastTarget)) { //递归寻找下一个长度
                return true;
            } else {
                visited[j] = false;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 4 > 0) {
            return false;
        }
        int edge = sum / 4;
        int res = 0;
        vector<bool> visited(size, false);
        for (int i=size-1; i>=0; i--) {
            if (visited[i]) {
                continue;
            }
            if (findSum(nums, visited, i, edge)) {
                res++;
            }
        }
        if (res != 4) {
            return false;
        }
        return true;
    }

};
```
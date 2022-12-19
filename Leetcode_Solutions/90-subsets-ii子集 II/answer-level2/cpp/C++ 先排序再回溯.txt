这道题和78题太像了，但是需要处理重复数字的问题。在解决这道问题之前，可以先考虑写出78题的回溯代码，然后在那个代码的基础之上进行调整。
思路：
- 先排序，将相同的数字放在一起，相同的数字看作「一组」
- 递归调用的时候以「组」为单位进行遍历，一个组中的数字看作一个数字

下面贴出代码，代码中也有解释我的思路
```cpp
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
public:
    Solution() {
        ret.clear();
        cur.clear();
        ret.push_back({});
    }

    void helper(vector<int>& nums, int start) {
        int pre = -1;
        for (int i = start; i < nums.size(); i++) {
            if (pre == -1 || pre != nums[i]) {
                cur.push_back(nums[i]);
                ret.push_back(cur);
                helper(nums, i + 1);
                cur.pop_back();
            }
            pre = nums[i];
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 这道题就不能用78题的回溯的方法直接写了，因为使用回溯的方法无法解决重复子集的问题「使用hash去重除外」
        // 解决思路：首先对数组进行排序，将相同的数字放在同一个区间
        // 然后在每次递归调用回溯函数helper的时候加一个判断，以区间为单位进行遍历即可。
        // 下面的代码执行用时超过53.13%， 内存消耗超过100%提交答案。
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ret;
    }
};
```

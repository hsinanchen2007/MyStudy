对大小为k的滑动窗口元素，使用set排序，寻找当前num在集合中的上界upper和下界lower,判断绝对差是否小于等于t。
注意，C++使用multiset可以保存重复元素，lower_bound仅返回不小于给定key值的最小下标low,其上界为low,下界为low-1。
```
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> win;
        for(int i=0; i<nums.size(); win.insert(nums[i++])){
            if (i>k) win.erase(win.find(nums[i-k-1]));
            auto low=win.lower_bound(nums[i]);
            if (low!=win.end() && 0L+*low-nums[i]<=t) return true;
            if (low!=win.begin() && 0L+nums[i]-*--low<=t) return true;
        }
        return false;
    }
};
```

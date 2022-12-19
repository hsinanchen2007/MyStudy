众所周知，c++拥有着强大的STL库，我们c++oier引以为豪，lower_bound是求出大于等于给定值的第一个数，返回的是一个迭代器，upper_bound是返回第一个大于给定值的数，
equal_range则是合二为一
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>*nums.rbegin()) return nums.size();
        vector<int>::iterator iter=lower_bound(nums.begin(),nums.end(),target);
        return abs(distance(iter,nums.begin()));
    }
};
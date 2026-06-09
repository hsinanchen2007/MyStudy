执行用时 :8 ms, 在所有 C++ 提交中击败了99.13%的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了79.45%的用户、
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    return nums[nums.size() - k];
}
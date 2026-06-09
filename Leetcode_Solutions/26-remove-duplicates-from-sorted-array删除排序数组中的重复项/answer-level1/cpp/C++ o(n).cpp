```c++
int removeDuplicates(vector<int>& nums) {
    int last_index = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[++last_index] = nums[i];
        }
    }
    return last_index + 1;
}
```
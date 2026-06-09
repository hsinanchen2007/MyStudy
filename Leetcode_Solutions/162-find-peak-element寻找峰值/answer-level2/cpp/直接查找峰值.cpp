class Solution {
public:
    int JudgeIsPeak(int index, vector<int>& nums) {
        int result = -1;
        if (index == 0) {
            if (nums.at(index) > nums.at(index + 1)) {
                result = index;
            }
        } else if (index == nums.size() - 1) {
            if (nums.at(index) > nums.at(index - 1)) {
                result = index;
            }
        } else {
            if (nums.at(index) > nums.at(index + 1) && nums.at(index) > nums.at(index - 1)) {
                result = index;
            }
        }
        return result;
    }

    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            int i = nums.at(0) > nums.at(1) ? 0 : 1;
            return i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (JudgeIsPeak(i, nums) != -1) {
                return i;
                //vec.emplace_back(i);
            }
        }
        return -1;
    }
};
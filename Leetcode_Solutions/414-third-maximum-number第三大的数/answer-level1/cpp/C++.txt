class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int temp;
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) {
            if (nums[0] >= nums[1]) return nums[0];
            else return nums[1];
        }
        else if (nums.size() == 3) {
            if(nums[0] > nums[1]) temp = nums[0], nums[0] = nums[1], nums[1] = temp;
            if(nums[1] > nums[2]) temp = nums[1], nums[1] = nums[2], nums[2] = temp;
            if(nums[0] > nums[1]) temp = nums[0], nums[0] = nums[1], nums[1] = temp;
            int max_1 = nums[0];
            int max_2 = nums[1];
            int max_3 = nums[2];
            if (max_1 == max_2 || max_2 == max_3) return max_3;
            else return max_1;
        } else {
            if(nums[0] > nums[1]) temp = nums[0], nums[0] = nums[1], nums[1] = temp;
            if(nums[1] > nums[2]) temp = nums[1], nums[1] = nums[2], nums[2] = temp;
            if(nums[0] > nums[1]) temp = nums[0], nums[0] = nums[1], nums[1] = temp;
            int max_1 = nums[0];
            int max_2 = nums[1];
            int max_3 = nums[2];
            for (int i = 3; i < nums.size(); i++) {
                if (nums[i] < max_1) {
                    if (max_1 == max_2) max_1 = nums[i];
                    if (max_2 == max_3) {
                        max_2 = max_1;
                        max_1 = nums[i];
                    }
                }
                if (nums[i] > max_1 && nums[i] < max_2) max_1 = nums[i];
                if (nums[i] > max_2 && nums[i] < max_3) {
                    max_1 = max_2;
                    max_2 = nums[i];
                }
                if (nums[i] > max_3) {
                    max_1 = max_2;
                    max_2 = max_3;
                    max_3 = nums[i];
                } 
            }
            if (max_1 == max_2 || max_2 == max_3) return max_3;
            else return max_1;
        }
    }
};

    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());

        int left = 0, right = 1;
        while (right < nums.size()) {
            int diff = nums[right] - nums[left];
            if (diff == k) {
                count++;
                while (right < nums.size() - 1 && nums[right + 1] == nums[right]) {
                    right++;
                }
                while (left < right && nums[left + 1] == nums[left]) {
                    left++;
                }
                left++;
                do {
                    right++;
                } while (left >= right);
            } else if (diff > k) {
                left++;
                if (left >= right) {
                    right++;
                }
            } else {
                right++;
            }
        }
        return count;
    }
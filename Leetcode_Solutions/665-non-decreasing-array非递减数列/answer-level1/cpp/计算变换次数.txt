观察非递减序列的规则。进行问题场景分解：
场景1：如果是变换的是首个元素。那么将首个元素变换为后一个元素值：nums[0] = nums[1]。变换次数加1。
场景2：如果变换的不是首个元素，那么观察其前一个元素如果小于后一个元素，那么将当前元素变换为前一个元素值：nums[i] = nums[i-1]。否则将其后一个元素变换为当前值：nums[i+1] = nums[i]。变换次数加1。


bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 1) {
            return true;
        }
        
        int switchedCount = 0;
        for (int i=0; i<nums.size()-1; ++i) {
            if (nums[i]>nums[i+1]) {
                if (i == 0) {
                    nums[i] = nums[i+1];
                }
                else if (nums[i-1]<nums[i+1]) {
                    nums[i] = nums[i-1];
                }
                else {
                    nums[i+1] = nums[i];
                }
                
                switchedCount++;
            }
        }
        
        return (switchedCount<=1);
    }
```
vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j)
        {
            while(i < j && nums[i] & 1) 
                i++;
            while(i < j && (nums[j] & 1) == 0)
                j--;
            if(i < j)
                swap(nums[i++],nums[j--]);
        }
        return nums;
    }
```

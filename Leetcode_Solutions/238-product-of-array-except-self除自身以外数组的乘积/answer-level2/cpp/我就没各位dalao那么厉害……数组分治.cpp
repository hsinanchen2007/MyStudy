class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //复杂度稍高一点 O(nlogn)
        int nsize = nums.size();
        vector<int> res(nsize, 1);
        doproduct(nums, res, nsize/2, 0, nsize);
        return res;
    }
    void doproduct(vector<int>& nums, vector<int>& res, int center, int start, int end)
    {
        if(start >= end) return;
        
        int left = 1, right = 1;
        for(int i=start;i<center;++i)
            left *= nums[i];
        for(int i=center+1;i<end;++i)
            right *= nums[i];
        res[center] *= (left * right);
        left *= nums[center];
        right *= nums[center];
        for(int i=start;i<end;++i)
        {
            if(i < center)
                res[i] *= right;
            if(i > center)
                res[i] *= left;
        }
        doproduct(nums, res, (start+center)/2, start, center);
        doproduct(nums, res, (center+end)/2, center+1, end);
        return ;
    }
};
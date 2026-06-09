class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket(3);
        for(auto val:nums)
        {
            bucket[val]++;
        }
        int k=0;
        for(int i=0;i<bucket.size();i++)
        {
            for(int j=0;j<bucket[i];j++)
            {
                nums[k++]=i;
            }
        }
    }
};
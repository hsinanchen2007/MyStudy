class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>::iterator iter;
        //1. 将较小的数组交换到nums1
        if(nums1.size()>nums2.size())
            std::swap(nums1,nums2);
        
        int lenth = nums1.size();
        for(int i = 0; i<lenth; i ++)
        {
            //2. 找出两个数组中相同的数
            iter = find(nums2.begin(),nums2.end(),nums1[i]);
            if(iter!=nums2.end())
            {
                //在nums2中删除该数，并保存在res中
                nums2.erase(iter);
                
                res.push_back(nums1[i]);
            }
        }
        return res;
    }
};
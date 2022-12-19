```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size()||!nums2.size()) return {};
        vector<int> ans;
        sort(nums1.begin(),nums1.end());//因为1短，对1排序,然后根据2在1中二分查找
        for(auto v : nums2){
            int l = 0, r = nums1.size() - 1;//下面就是常规二分了
            while(l < r){
                int mid = l + r>>1;
                if(nums1[mid] >= v) r = mid;
                else l = mid + 1;
            }
            if(nums1[l]==v){//查找成功时
                ans.push_back(v),nums1.erase(nums1.begin() + l);
                if(!nums1.size()) break;
            } 
        }
        return ans;
    }
};
```

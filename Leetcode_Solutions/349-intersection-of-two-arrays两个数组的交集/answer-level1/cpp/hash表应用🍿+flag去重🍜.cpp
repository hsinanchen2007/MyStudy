```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset;
        vector<int> ans;
        int flag[100005] = {0};
        for(int i = 0; i < nums1.size(); i++) {
            hashset.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(hashset.count(nums2[i]) && !flag[nums2[i]]) {
                ans.push_back(nums2[i]);
                flag[nums2[i]] = 1;
            }
        }
        return ans;
    }
};
```

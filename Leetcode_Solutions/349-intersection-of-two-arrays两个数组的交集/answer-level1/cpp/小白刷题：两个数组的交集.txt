nums1利用set去重，nums2查找交集元素

代码：
```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> temp;
        vector<int> ans;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for (int i = 0; i < len1; i++)
            temp.insert(nums1[i]);
        for(int i = 0; i < len2; i++) {
            if(temp.find(nums2[i]) != temp.end() && find(ans.begin(), ans.end(), nums2[i]) == ans.end())
                ans.push_back(nums2[i]);
        }
        return ans;
    }
};
```

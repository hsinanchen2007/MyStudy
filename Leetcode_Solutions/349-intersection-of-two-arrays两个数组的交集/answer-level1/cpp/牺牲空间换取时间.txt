本题借助了一个bool 数组来完成解题,但是该方法有一个弊端就是你不能确定所给出的最大数据最大是多大所以需要解题人对大概的数据有一个预估 
奉上AC代码:
```
class Solution {
public:
    vector<int> ans;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool vis[9999] = {0};
        for(int i=0;i<nums1.size();i++)vis[nums1[i]] = 1;
        for(int i=0;i<nums2.size();i++)
        if(vis[nums2[i]] == 1){ans.push_back(nums2[i]);vis[nums2[i]] = 0;}
        return ans;
    }
};
```

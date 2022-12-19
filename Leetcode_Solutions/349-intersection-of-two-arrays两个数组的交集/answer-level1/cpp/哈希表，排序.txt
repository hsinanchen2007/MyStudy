### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()==0||nums1.size()==0)
            return{};
        map<int,int>maps;
        vector<int>vec;
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            maps[nums1[i]]=nums1[i];
        }
        for(int j=0;j<nums2.size();j++){
            if(j>0&&nums2[j]==nums2[j-1]) continue;
            if(maps.count(nums2[j]))
                vec.push_back(nums2[j]);
        }
        return vec;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(nums1.size()==0|| nums2.size()==0){
            return ans;
        }

        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]>0){
                ans.push_back(nums2[i]);
                m[nums2[i]]=0;
            }
        }

        return ans;
    }
};
```
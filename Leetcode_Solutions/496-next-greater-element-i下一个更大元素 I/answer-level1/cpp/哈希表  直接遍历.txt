### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
      
        unordered_map<int,int> hash;
        for(int i = 0;i< nums1.size();i++){
            hash[nums1[i]] = -1;
            bool flag = false;
            for(int j = 0;j<nums2.size();j++){
                if(nums2[j] == nums1[i]) flag = true;
                if(nums2[j] > nums1[i] && flag == true){
                    hash[nums1[i]] = nums2[j];
                    break;
                }
            }
        } 
        for(int i = 0;i<nums1.size();i++){
            int temp = hash[nums1[i]];
            res.push_back(temp);
        }
        return res;
    }
};
```
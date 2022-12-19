### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a;
        map<int,int>table = {};
        for(int i = 0;i<nums1.size();i++){
            if(table.count(nums1[i])== 0){
                table.insert(map<int,int>::value_type(nums1[i],1));
            }
        }
        for(int i = 0;i<nums2.size();i++){
            if(table.count(nums2[i]) != 0 && table[nums2[i]] != 0){
                a.push_back(nums2[i]);
                table[nums2[i]]  = 0;
            }
        }
        return a;
    }
};
```
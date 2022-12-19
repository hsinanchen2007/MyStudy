### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int >vec;
        int len1=nums1.size();
        int len2=nums2.size();       
        map<int,int>maps;
        for(int i=0;i<len1;i++){
            if(!maps.count(nums1[i]))
                maps[nums1[i]]=1;      //第一次出现赋值1
            else
                maps[nums1[i]]++;      //再次出现就++
        }
        for(int j=0;j<len2;j++){
            if(maps.count(nums2[j])&&maps[nums2[j]]){
                vec.push_back(nums2[j]);
                maps[nums2[j]]--;
            }
        }
        return vec;
    }
};
```
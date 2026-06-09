### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    // //哈希
    // unordered_map<int,int>m;
    // for(auto i : nums1){
    //     m[i]++;
    // }
    // for(int i=0;i<nums2.size();i++){
    //     if(m[nums2[i]]>0){
    //         m[nums2[i]]--;
    //         res.push_back(nums2[i]);
    //     }
    // }
    // return res;

    //排序（模拟输入数组是有序的）
    sort(nums2.begin(),nums2.end());
    sort(nums1.begin(),nums1.end());
    //两个指针，分别遍历nums1和nums2
    int i=0,j=0;
    while(i<nums1.size()&&j<nums2.size()){
        if(nums1[i]==nums2[j]){
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else j++;
    }
    return res;
    }
};
```
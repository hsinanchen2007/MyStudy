### 解题思路
将num1建立一个unordered_set为m,查找nums2中的元素是否在m中，在的话加入vector res中，并且删除在m中的该元素，避免待会儿出现重复

### 代码


```cpp

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
   
        unordered_set<int> m(nums1.begin(), nums1.end()); //将第一个数组的元素建立一个unordered_set
        vector<int> res;//建立关于结果的vector

        for(int a:nums2)
            if( m.erase(a))  //既查找了m中是否存在a,又完成了删除a的工作，避免后续过程重复元素
            res.push_back(a);//在vector res的末尾加入a

        return res;
    }
};

```
```
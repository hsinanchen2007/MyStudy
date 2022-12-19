### 解题思路
1.将nums1所有出现过的数组都压入set集合中。
2.遍历nums2所有的元素，查找是否在set集合中，若存在则将集合中的元素压入res容器中，并删除set集合的对应元素。

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(),nums1.end());
        vector<int> res;
        
        for(int i : nums2){
            if(m.erase(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
```
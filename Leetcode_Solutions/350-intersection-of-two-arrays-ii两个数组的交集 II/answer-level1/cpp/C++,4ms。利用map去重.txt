### 解题思路
思路：利用map去重数组1中的元素，然后查询数组2中的每个元素是否与map的key相同，若相同则添加入结果数组，同时对应value减1.

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        unordered_map<int,int> map;
        for(int i : nums1){
            ++map[i];
        }
        for(int i : nums2){
            if(map.count(i)) {               
                if(map[i] > 0)
                    res.push_back(i);
                map[i] --;
            }
        }
        return res;
        }
};
```
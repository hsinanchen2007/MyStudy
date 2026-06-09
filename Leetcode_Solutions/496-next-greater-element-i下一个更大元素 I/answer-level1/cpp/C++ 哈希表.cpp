![image.png](https://pic.leetcode-cn.com/9b00ac0f37293993074f9475964a0e7fb3faa9872ce171e90403c8763a3e3a8e-image.png)
解题思路：哈希表存储数组一中每个值在数组二中的坐标，再往后遍历。
```
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        vector<int> res;
        int index = 0;
        for(auto itm : nums2){
            hashmap[itm] = index++;
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=hashmap[nums1[i]];j<nums2.size();j++){
                if(nums1[i] < nums2[j]){
                    res.push_back(nums2[j]);
                    break;
                }
                else{
                    if(j == nums2.size()-1){
                        res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
```


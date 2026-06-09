### 解题思路
然后遍历比较即可，遇到更大的元素就跳出，如果遍历完了还没找到就放-1

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n = nums2.size();
        unordered_map<int, int> hashmap;
        vector<int> res;
        int idx = 0;
        for(auto num : nums2){
            hashmap[num] = idx++;
        }
        for(int i=0;i<m;i++){
            for(int j=hashmap[nums1[i]];j<n;j++){
                if(nums1[i] < nums2[j]){
                    res.push_back(nums2[j]);
                    break;
                }
                else{
                    if(j == n-1){
                        res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
};
```
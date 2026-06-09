### 解题思路
利用unordered_map存储每个数组元素i出现的次数，
若target-i出现过，就一起放入返回容器中，并将target-i出现的次数减1
否则将i出现的次数加1
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<vector<int>>res;
        for(auto i : nums){
            if(m[target-i]>0){
                m[target-i]--;
               res.push_back({target-i,i}); 
            }
            else m[i]++;
        }
        return res;
    }
};
```
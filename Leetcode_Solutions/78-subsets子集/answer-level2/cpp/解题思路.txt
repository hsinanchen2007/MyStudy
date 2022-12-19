### 解题思路
递归问题

### 代码

```cpp
class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > result;
        if(nums.size()==0){
            result.push_back(vector<int>());
        }
        else{
            vector<int> subItem(nums);
            subItem.erase(subItem.begin());
            vector< vector<int> > item = subsets(subItem);
            result.insert(result.end(),item.begin(),item.end());
            for(vector<int> p : item){
                p.push_back(nums[0]);
                result.push_back(p);
            }
            return result;
        }
        return result;
    }
};
```
核心思路：从用前i个元素构成子集一路推到用整个nums数组构成子集

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int> {});
        for(int i=0;i<nums.size();i++){
            int pre_ret_size = ret.size();  //在下面的循环后ret会不断增大，所以要提前记录当前大小
            for(int j=0;j<pre_ret_size;j++){
                vector<int> tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }

};
```

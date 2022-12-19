### 解题思路


![image.png](https://pic.leetcode-cn.com/37cf487e83f94e3b39281c4a0a71a0fc39d441e693f98cbcc62cf9dacb7c9bb6-image.png)


因为是遍历所有的可能子集
所以在递归函数内并没有递归结束条件
让它一直递归出所有可能


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0){
            return res;
        }
        vector<int> temp;

        process(0,nums,temp);
        return res;
    }


private:
    void process(int start,vector<int> nums,vector<int> temp){
        res.push_back(temp);

        for(int i = start;i<nums.size();i++){
            temp.push_back(nums[i]);
            process(i+1,nums,temp);
            temp.pop_back();
        }
        

    }
};
```
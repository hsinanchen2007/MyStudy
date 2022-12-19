### 解题思路
利用回溯法，不超过数组终点时就纳入可行性解，超过数组终点时就返回上一个状态。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int num=0;
        solu(nums,num);    
        return res;
    }
    void solu(vector<int>& nums,int num){
        if(num<=nums.size()){
            res.push_back(ans);
        }
        for(int i=num;i<nums.size();i++){
            ans.push_back(nums[i]);
            solu(nums,i+1);
            ans.pop_back();
        }
    }

};
```
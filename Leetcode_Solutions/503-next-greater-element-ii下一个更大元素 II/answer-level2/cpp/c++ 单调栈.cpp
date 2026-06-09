```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty())return {};
        stack<int> s;
        vector<int> res(nums.size(),-1);
        for(int i=0;;++i){
            while(!s.empty()&&nums[s.top()]<nums[i%nums.size()]){
                res[s.top()]=nums[i%nums.size()];
                s.pop();
            }
            if(s.size()==1&&s.top()==i%nums.size()||i>2*nums.size())return res;
            s.push(i%nums.size());
        }
    }
};
```

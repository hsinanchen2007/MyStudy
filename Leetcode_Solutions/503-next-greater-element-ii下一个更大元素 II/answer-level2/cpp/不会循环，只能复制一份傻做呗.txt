思路是将数组复制一份，然后使用维护一个递减栈，也就是栈中元素都比栈顶小，向栈低依次递减
可以看一下循环的做法
```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size()*2,1);
        int n = nums.size();
        vector<int> help = nums;
        nums.insert(nums.end(),help.begin(),help.end());
        for(int i = 0; i < nums.size();i++){
            while(!s.empty() && nums[i]> nums[s.top()] ){
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()] = -1;
            s.pop();
        }
        return vector<int>(res.begin(),res.begin()+n);
    }
};
```

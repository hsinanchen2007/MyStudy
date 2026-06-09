```
class Solution {
public:
    vector<int> nums;
    vector<char> ops;
    
    vector<int> helper(int left,int right){
        vector<int> ret;
        if(left == right){
            ret.push_back(nums[left]);
        }else{
            for(int i = left;i<right;i++){
                vector<int> ls = helper(left,i);
                vector<int> rs = helper(i+1,right);
                for(int j=0;j<ls.size();j++){
                    for(int k = 0;k<rs.size();k++){
                        switch(ops[i]){
                            case '+' : ret.push_back(ls[j] + rs[k]);break;
                            case '-' : ret.push_back(ls[j] - rs[k]);break;
                            case '*' : ret.push_back(ls[j] * rs[k]);break;
                            default:break;
                        }
                    }
                }
            }
        }
        
        return ret;
    }
    
    vector<int> diffWaysToCompute(string input) {
        int val = 0;
        for(int i=0;i<input.size();i++){
            if(isdigit(input[i])){
                val = val * 10 + input[i] - '0';
            }else{
                nums.push_back(val);
                val = 0;
                ops.push_back(input[i]);
            }
        }
        nums.push_back(val);
        
        return helper(0,nums.size()-1);
        
    }
    
    
};
```

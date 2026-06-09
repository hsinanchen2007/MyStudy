### 解题思路
用递归算法，比如[2,4,6],target = 8,遍历数组，对每一个元素，用8去整除，保存下除数,分别遍历一个到除数个这个元素，从后面数列中遍历地调用这个递归函数，新的的target = target - 遍历的除数*这个元素。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> find(vector<int>& candidates, int index, int target){
        vector<vector<int>> ret;
        if(index >= candidates.size()){
            return ret;
        }
        if(candidates[index] == target){
            ret.push_back(vector<int>(1,target));
            return ret;
        }

        for(int i = target/candidates[index]; i >= 1; i--){
            vector<int> vec(i, candidates[index]);
            if(target-i*candidates[index]==0){
                ret.push_back(vec);              
            }
            else if(target-i*candidates[index]>0){
                for(int g = 1; g < candidates.size()-index; g++){
                    vector<vector<int>> ret_temp = find(candidates, index+g, target-i*candidates[index]);         
                    for(int j = 0; j< ret_temp.size(); j++){
                        vector<int> vec2 = vec;
                        for(int k = 0; k < ret_temp[j].size(); k++)
                            vec2.push_back(ret_temp[j][k]);
                        ret.push_back(vec2);
                    }
                }
                
            }
            
        }  
        return ret;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<vector<int>> ret_temp;
        for(int i = 0; i < candidates.size(); i++){
            ret_temp = find(candidates, i, target);    
            for(int j = 0; j < ret_temp.size(); j++)
                ret.push_back(ret_temp[j]);
        }
        
        return ret;
    }
};
```
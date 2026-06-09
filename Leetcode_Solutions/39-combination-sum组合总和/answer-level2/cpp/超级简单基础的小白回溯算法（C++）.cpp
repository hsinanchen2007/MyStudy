
![image.png](https://pic.leetcode-cn.com/bf866403321c8cb8c52cef19541f82e4041b4d507f630db26a45c9368e85f3d8-image.png)

思路非常简单 
就是装一个 如果不行 就递归 再装下一个
为了防止重复
只允许从自己开始 往后头找
```
#include <iostream>
using namespace std;
class Solution {
public:    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> output;
        if(candidates.size()==0){
            return output;
        }
        vector<int> tmp;
        for(int i=0;i<candidates.size();i++){
          tmp.push_back(candidates[i]);
          answer(output,target-candidates[i],i,tmp,candidates);  
          vector<int> ().swap(tmp);
        }
        return output;
    }
    
    void answer(vector<vector<int>> &output,int sum,int a,vector<int> &tmp,vector<int>&candidates){
        if(sum <= 0){
            if(sum == 0){
             output.push_back(tmp);   
            }
            return;
        }
        
        for(int i=a;i<candidates.size();i++){
               tmp.push_back(candidates[i]);
               answer(output,sum-candidates[i],i,tmp,candidates);
               tmp.pop_back();
        }        
        return;
    }
};
```

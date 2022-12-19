### 解题思路
加加减减就完了

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ret;
        if(target<3)
         return ret;
        int left=1,right=2;
        int num_ret=-1;
        int sum=left+right;
        while(right-left>0){
            if(sum==target){
                num_ret++;
                ret.push_back({});
            
                 for(int i=left;i<=right;i++){
                         ret[num_ret].push_back(i);
                 }
                 ++right;
                 sum+=right;   
            }
            else if(sum>target){
                ++left;
                sum-=left-1;
            }
            else if(sum<target){
                ++right;
                sum+=right;
            }
        }
        return ret;
        
    }
};
```
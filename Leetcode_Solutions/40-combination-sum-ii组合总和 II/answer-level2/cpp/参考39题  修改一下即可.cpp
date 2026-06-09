```
class Solution {
public:
    vector<vector<int>>out;
    vector<int>tmp;
    void result(int idx,vector<int>& candidates,int  target)
    {
        if(target<=0){
            if(target==0){
                        out.push_back(tmp);
                    }
            return;
        }
        for( int i=idx ; i<candidates.size() ; i++){
            //去掉重复
         if( i>idx&&candidates[i]==candidates[i-1])
             continue;
            tmp.push_back(candidates[i]);
            result(i+1,candidates,target-candidates[i]);
            tmp.pop_back(); 
        }       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());//排序
        result(0,candidates,target);
        return out;
    }
```

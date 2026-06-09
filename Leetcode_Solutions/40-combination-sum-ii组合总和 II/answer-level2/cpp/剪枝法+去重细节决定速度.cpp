### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> temp;
      if(candidates.size()==0) return ans;
      sort(candidates.begin(),candidates.end());//排序
      for(int i=0;i<candidates.size();i++){
      if(candidates[i]>target)  break;
      combination(candidates,target-candidates[i],candidates[i],i,temp);
      while(i<candidates.size()-1&&candidates[i]==candidates[i+1])
            i++;//去掉重复项
      }
    return ans;
    }

    void combination(vector<int> candidates,int target,int cuttree,int pos,vector<int> temp)//记录目标数，剪切数，遍历所在位置；
    {   
         if(target==0){
            temp.push_back(cuttree); 
            ans.push_back(temp);  
         }
         temp.push_back(cuttree);      
         if(cuttree>target) return;//剪枝   
         else{
             for(int j=pos+1;j<candidates.size();j++){
              if(candidates[j]>target) break;//大于目标值时，终止递归；      
              combination(candidates,target-candidates[j],candidates[j],j,temp);
              while(j<candidates.size()-1&&candidates[j]==candidates[j+1])//去掉重复项
            j++;
             }          
         }
         
    }
};
```
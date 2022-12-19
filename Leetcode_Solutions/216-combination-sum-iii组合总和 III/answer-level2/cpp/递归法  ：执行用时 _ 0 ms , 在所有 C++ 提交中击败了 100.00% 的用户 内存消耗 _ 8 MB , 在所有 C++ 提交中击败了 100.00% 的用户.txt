### 解题思路
此处撰写解题思路
递归法，遍历所有组合。确定条件减少遍历时间
### 代码

```cpp
class Solution {
public:
    void Sum3(vector<int>&res,vector<vector<int>>  &result,int k,int n,int num){

    if(res.size()>k)
    {
        return;
    }
     if(res.size()==k ){

         int sum=0;
         for (int j = 0; j < res.size(); ++j) {
             sum+=res[j];
         }
         if(sum==n)
         {
             result.push_back(res);
         }
         return;
     }

    for (int i = num; i <10 ; ++i) {
        res.push_back(i);
        Sum3(res,result,k,n,i+1);
        res.pop_back();
    }
 }
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>res;
    vector<vector<int>>  result;
    Sum3(res,result,k,n,1);
    return result;
}

};
```
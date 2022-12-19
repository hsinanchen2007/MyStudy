![image.png](https://pic.leetcode-cn.com/0008eccbb7d37e479c7dbf8f02ef26af2fcf1e3be11006d5f62843ac614a9a20-image.png)

不太理想的结果 但是就是比题1 多了有重复数的情况
看了一下网上的题解
去重 = 一开始的排序+下标的移动【而我忽略了下标的移动，反而还多了一个set的驱虫重，空间和时间都有更多的损耗】
大概意思就是
a =【1，2，2，2，3】
a[1] = 2
下一次就取a[4] =3因为多余的2 结果是一样的

```
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        if(candidates.size()==0){
            return output;
        }
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        for(int i=0;i<candidates.size();i++){
          tmp.push_back(candidates[i]);
          answer(output,target-candidates[i],i,tmp,candidates);  
          vector<int> ().swap(tmp);
        }
        set<vector<int>> st(output.begin(),output.end());
        output.assign(st.begin(),st.end());
        return output;
    }
    void answer(vector<vector<int>> &output,int sum,int a,vector<int> &tmp,vector<int>&candidates){
        if(sum <= 0){
            if(sum == 0){
             output.push_back(tmp);   
            }
            return;
        }
        
        for(int i=a+1;i<candidates.size();i++){
               tmp.push_back(candidates[i]);
               answer(output,sum-candidates[i],i,tmp,candidates);
               tmp.pop_back();
        }        
        return;
    }
};
```

执行用时 :8 ms, 在所有 C++ 提交中击败了92.76%的用户
内存消耗 :13.4 MB, 在所有 C++ 提交中击败了24.78%的用户


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ans_tmp;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        function<void(int)> backTrace=[&](int start){//lambda表达式简化ans,ans_tmp,sum的引用传递
            if(sum>target)//递归结束条件
                return ;
            if(sum==target)
                ans.push_back(ans_tmp);
            for(int i=start;i<candidates.size();i++)
            {
                sum+=candidates[i];
                ans_tmp.push_back(candidates[i]);
                backTrace(i);//元素可以重复使用
                ans_tmp.pop_back();
                sum-=candidates[i];
                if(sum+candidates[i]>target)
                { 
                    break;//如果当前元素已经大于target，之后的元素则不需要在计算了
                }
                

            }
        };
        backTrace(0);//调用递归函数
        return ans;
    }
};
```
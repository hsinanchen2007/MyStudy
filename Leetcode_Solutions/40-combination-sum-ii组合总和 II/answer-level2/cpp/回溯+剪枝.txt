# 回溯
1. 先排序；
2. 由于同一个数字只能使用一次，因此在深度遍历时从第i+1个找起；
3. 保留深度方向上相同的数字（也就是多个重复数字时可用，比如[1,1,1],第一个‘1’使用过后，第二和第三个依然可以使用），剔除水平方向相同的（也就是同一层中相同的枝应该剪掉）。
代码如下：
```
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        if(len == 0)
            return m_res;
        vector<int> res;
        sort(candidates.begin(),candidates.end());
        dfs(target,0,candidates,len,res);
        return m_res;
    }
    
    void dfs(int target,int start,vector<int>& candidates,int len,vector<int> res){
        int i;
        for(i = start;i < len && target > candidates[i];++i){
            res.push_back(candidates[i]);
            //深度遍历从i+1起
            dfs(target-candidates[i],i+1,candidates,len,res);
            //执行到此时说明第i个元素不应该记录在res中
            res.pop_back();
            //剔除水平方向相同的枝
            while(i+1 < len && candidates[i+1] == candidates[i])
                i = i+1;
        }
        if(i < len && target == candidates[i]){
            res.push_back(candidates[i]);
            m_res.push_back(res);
        }
    }
    
    private:
        vector<vector<int>> m_res;
};
```

# 思想：回溯算法

[参考](https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/)

![1.png](https://pic.leetcode-cn.com/96679ca866f6838a70c9272e078f4d4ff24683b5fa38cc9fa8d2945d17e35cab-1.png)



[组合总和](https://leetcode-cn.com/problems/combination-sum/)
```
class Solution {
public:
    void dfs(vector<int>& candidates, int begin, int size, vector<int> & path, vector<vector<int> > & res, int target) {
        // 终止
        if(target == 0) {
            res.push_back(path);
        }
        for(int i=begin; i<size; i++) {
            int residue = target - candidates[i];
            if(residue < 0) break;
            
            path.push_back(candidates[i]);
            dfs(candidates, i, size, path, res, residue);
            path.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if(candidates.size() == 0) return res;
        // 剪枝的前提是数组元素排序
        // 深度深的边不能比深度浅的边还小
        // 要排序的理由：1、前面用过的数后面不能再用；2、下一层边上的数不能小于上一层边上的数。
        sort(candidates.begin(), candidates.end());
        
        vector<int> path;
        dfs(candidates, 0, candidates.size(), path, res, target);
        return res;
    }
};
```

[组合总和2](https://leetcode-cn.com/problems/combination-sum-ii/)
```
class Solution {
public:
    
    void dfs(vector<int>& candidates, int begin, int size, vector<int> & path, vector<vector<int> > & res, int target) {
        // 终止
        if(target == 0) {
            // 如果已存在，则去重
            if(find(res.begin(), res.end(), path) == res.end())
                res.push_back(path);
        }
        for(int i=begin; i<size; i++) {
            int residue = target - candidates[i];
            if(residue < 0) break;
            
            path.push_back(candidates[i]);
            dfs(candidates, i+1, size, path, res, residue);
            path.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if(candidates.size() == 0) return res;
        // 剪枝的前提是数组元素排序
        // 深度深的边不能比深度浅的边还小
        // 要排序的理由：1、前面用过的数后面不能再用；2、下一层边上的数不能小于上一层边上的数。
        sort(candidates.begin(), candidates.end());
        
        vector<int> path;
        dfs(candidates, 0, candidates.size(), path, res, target);
        return res;
    }
};
```


[组合总和3](https://leetcode-cn.com/problems/combination-sum-iii/)
```
class Solution {
public:
    
    void dfs(vector<int>& candidates, int begin, int size, vector<int> & path, vector<vector<int> > & res, int n, int k) {
        // 终止
        if(n == 0 && path.size() == k) {
            res.push_back(path);
        }
        for(int i=begin; i<size; i++) {
            int residue = n - candidates[i];
            
            // 结束条件
            if(residue < 0) break;
            if(path.size() > k) break;
            
            path.push_back(candidates[i]);
            dfs(candidates, i+1, size, path, res, residue, k);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, 0, candidates.size(), path, res, n, k);
        return res;
    }
};
```


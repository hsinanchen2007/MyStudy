**请结合图解和注释，理解代码。希望能帮到大家，欢迎交流！**

# 图解
![image.png](https://pic.leetcode-cn.com/2b9f76ba2363e9e7526b8d62d004c8273781baffa53f33501e4b5e98592966a4-image.png)

# 源码及注释
```
set<multiset<int>> store;	//结果存储，利用set自动去除重复结果，利用multiset无视顺序的同时保留重复元素
void DFS(vector<int> cand, int curr, multiset<int>res) {//curr为当前目标curr_target
    if (curr == 0)                                      //res存储当前节点下已使用的数字
        store.insert(res);
    for (int i = 0; i < cand.size() && cand[i]<=curr; i++) {//剪枝
        res.insert(cand[i]);                                //存枝
        DFS(cand, curr - cand[i], res);                     //DFS
        res.erase(res.find(cand[i]));                       //回溯
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());             //升序排序
    DFS(candidates, target, multiset<int>{});               //DFS+回溯+剪枝
    for (auto it : store) {                                 //结果
        vector<int>tmp;
        for (int x : it)
            tmp.push_back(x);
        ans.push_back(tmp);
    }
    return ans;
}
```

# 有题友指出，本方法时间复杂度过高，下面针对该方法的漏洞，提出“大剪枝”方法，提高效率
![image.png](https://pic.leetcode-cn.com/2b0abb2c3b28233ffe65467581ab6a5fd9adfc480392d2e345b6ca2a0ea4ca1e-image.png)
```
vector<int> candidates;
vector<int> solu;
vector<vector<int>> res;
void DFS(int prevPos, int curr) {
    if (curr == 0) { res.push_back(solu); return; }
    for (int i = prevPos; i < candidates.size(); ++i) {
        if (candidates[i] > curr) continue;
        solu.push_back(candidates[i]);
        DFS(i, curr - candidates[i]);
        solu.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    this->candidates = candidates;
    DFS(0, target);
    return res;
}
```


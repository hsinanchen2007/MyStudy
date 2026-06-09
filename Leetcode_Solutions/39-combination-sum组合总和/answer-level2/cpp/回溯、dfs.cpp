该题和[组合总结3](https://leetcode-cn.com/problems/combination-sum-iii/)差不多。
坦白讲，这两道题，我做的时候都没有一个回溯法或者dfs的概念（看来题刷的不够多），虽然我的做法确实是dfs\回溯，但没有形成这是一种类型题的思维。说明现在解题思维还是过于随意，有思路就有，没有思路就没。缺点就是不够系统，有时候会遗漏一下前人系统化的知识和技巧（比如剪枝等等）。直到看到组合总和这道题突然觉得这不就是以前学的背包问题吗，这才回忆起来回溯这个概念。
效果体现在[子集](https://leetcode-cn.com/problems/subsets/solution/)这道题，之前没回溯的概念想不出来怎么做，而做完这道题回去看了一下，会明显发现这不就是回溯吗？（和组合总和有点小区别，可转化为选择与否的问题，也可仍用选择哪个的思路）
代码如下：
主要经过了两次修改，运行时间84ms->24ms->12ms。
第一次修改是for循环并不需要全部执行完，发现remain<candidates[i]时就要break了，**这才是“回溯”所在。我之前写的其实只是DFS搜索+剪枝。（这也真是回溯和dfs的区别所在，实际上回溯的操作也是一种剪枝）**
第二次修改是把一系列变量弄成成员变量，而不依靠函数参数传递。节省的时间出乎我的意料（参数传递值拷贝的消耗这么大吗？希望有人指点）
```
class Solution {
public:
    vector<vector<int>> output;
    vector<int> candidates;
    vector<int> v;
    void dfs(int remain,int k){//k表示上次选取数字的位置
        if(remain==0){
            output.push_back(v);
            return;
        }

        int i;
        for(i=k;i<candidates.size();i++){ //约束解的内部元素必须非递减，避免重复解
            if(remain<candidates[i])
                break;
            v.push_back(candidates[i]);
            dfs(remain-candidates[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        dfs(target,0);
        return output;
    }
};
```

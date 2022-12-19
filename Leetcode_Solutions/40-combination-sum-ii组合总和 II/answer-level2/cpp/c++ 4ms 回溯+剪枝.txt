解题思路：
很明显本题依然还是用dfs+回溯来解
但需要注意两个关键点：去重和剪枝
去重：
1. 首先要对candidates进行排序，方便去重
2. 每一轮搜索，除了开始的地方（start）可以跟前一个元素重复，其他的重复元素，全部跳过

剪枝
1. 排完序过后的candidates是递增的，所以我们可以用dfs return回来的值来判断需不需要剪枝
2. 当remain小于等于0的时候，显然后续的所有元素都不会满足要求了，应当剪枝，跳出循环

代码如下

```
class Solution {
    vector<vector<int> > res;
    vector<int> tmp;
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target);
        return res;
    }
    //此处用bool也可
    int dfs(vector<int>& candidates,int start,int remain){
        if(remain==0){
            res.push_back(tmp);
            //需要剪枝
            return 1;
        }
        //需要剪枝
        if(remain<0) return 1;
        for(int i=start;i<candidates.size();i++){
            //去重
            if(i>start&&candidates[i]==candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            int flag=dfs(candidates,i+1,remain-candidates[i]);
            tmp.pop_back();
            //进行剪枝，跳出循环
            if (flag==1) break;
        }
        return 0;
    }
};
```
![WX20200217-112752@2x.png](https://pic.leetcode-cn.com/1a2d7e6a2f60a86fc3a567b1cd7d65ddd479ce60d8598d657ddc1d0a06b63082-WX20200217-112752@2x.png)

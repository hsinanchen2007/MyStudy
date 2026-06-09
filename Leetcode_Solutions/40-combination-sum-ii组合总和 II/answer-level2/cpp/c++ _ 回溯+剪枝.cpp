![图片.png](https://pic.leetcode-cn.com/b1743c93a9bb50433f6c2fddee52dada195b1b9c2c8423dba92d89e0bf35d04a-%E5%9B%BE%E7%89%87.png)

### 解题思路
同39题的思路基本一样，画出树状图就清晰明了了。
不同点在于：
1. 39题中无重复元素，40题有重复元素，需要定义一个备忘录，当1和1'在同一层级时，避免出现[1,1',6]和[1',1,6]的情况；
2. 39题中数组的元素可以重复使用，40题中数组的元素只能使用一次，因此选择动作时，下一次的动作列表在i+1之后选择。

### 代码

```cpp
class Solution {
    vector<vector<int>> res;
    unordered_map<int,bool> mem;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        backtrack(path,candidates,target,0,0);
        return res;
    }
    //剪枝：start表示当前可选择数字的起始索引(避免重复：比如[1,2,5]和[1,5,2])
    void backtrack(vector<int> &path,vector<int>& candidates,int &target,const int &start,int total)
    {
        //结束条件
        if(total == target)
        {
            res.push_back(path);
            return;
        }
        //从动作列表选择动作
        int len = candidates.size();
        for(int i=start; i<len;i++)
        {
            //避免[1,1',6]和[1',1,6]的情况出现
            if(i>0 && candidates[i-1]==candidates[i] && mem[candidates[i-1]]==false) continue;
            //剪枝：因为数组已排序，此位置的数加进去后已经大于target，之后的数更不行
            if((total+candidates[i]) > target) break;

            mem[candidates[i]] = true;
            path.push_back(candidates[i]);
            total += candidates[i];

            backtrack(path,candidates,target,i+1,total);

            mem[candidates[i]] = false;
            path.pop_back();
            total -= candidates[i];
        }
    }
};
```
39题是组合数I，和这道题的区别是上一道题的数字是可以无限制重复使用的，这一题呢只能使用给出来的那些数字

那么我们的问题来了，要怎么样去排除我们的重复答案呢？
上一道题我们用大于等于back的数才能往下递归，这里除了这个以外，还需要注意的是，这里给出来的数字也可能重复，所以我们就需要在一层里面只用一次这个数字
```
class Solution {
    vector<vector<int>> res;
    vector<int> v;
    vector<int> candidates;
    void dfs(int remain, int idx)
    {
        if(remain == 0)
        {
            res.push_back(v);
            return;
        }
        if(idx == candidates.size() || remain < 0)
        {
            return;
        }
        for(int i = idx; i < candidates.size(); i++)
        {
            //在一层里面只用一次这个数字
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            v.push_back(candidates[i]);
            dfs(remain - candidates[i], i + 1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& _candidates, int target) {
        candidates = _candidates;
        sort(candidates.begin(), candidates.end());
        dfs(target, 0);
        return res;
    }
};
```
还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)


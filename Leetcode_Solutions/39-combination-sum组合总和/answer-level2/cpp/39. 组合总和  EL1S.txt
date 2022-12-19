这道题和78题，90题 求子集有几分相似，因为返回的结果都是组合数，但是这道题和78,90题的区别是，78题90题里面给出的数字是最多用一次的，这道题不同，给出的数字可能使用很多次。

对于这种不知道要求和多少次的，最适合用dfs来求解，让它自己去想要递归多少次，我们只要给出来停止条件就好了。
停止条件就是累加之后的结果正好等于target,又或者累加起来已经超过target了那这个就是个错误答案可以抛弃。

我们怎么样让结果不重复？
首先问一个问题：为什么会重复？ 
【2，2，3】 【3，2，2】这样就重复了
怎么出现的？ 因为后面的3再次用到了2
那么我们可以这样做：先把可选的数字从小到大排序，在寻找答案的过程中每次添加一个数字都只能添加大于等于它本身的

```
class Solution {
    vector<vector<int>> res;
    vector<int> candidates;
    vector<int> v;
    void dfs(int remain, int last)
    {
        if(remain == 0)
        {
            res.push_back(v);
            return;
        }
        if(remain < 0)
            return;
        // int l =  v.size() - 1;
        for(int i = last; i < candidates.size(); i++)
        {

                v.push_back(candidates[i]);
                dfs(remain - candidates[i], i);
                v.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& _candidates, int target) {
        candidates = _candidates;
        sort(candidates.begin(), candidates.end());
        dfs(target, 0);
        return res;
    }
};
```

第二种写法：减少参数
```
class Solution {
    vector<vector<int>> res;
    vector<int> candidates;
    vector<int> v;
    void dfs(int remain)
    {
        if(remain == 0)
        {
            res.push_back(v);
            return;
        }
        if(remain < 0)
            return;
        // int l =  v.size() - 1;
        for(auto x: candidates)
        {
            // cout << v[l];
            if(v.size() == 0 || x >= v.back())
            {
                v.push_back(x);
                dfs(remain - x);
                v.pop_back();
            }


        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& _candidates, int target) {
        candidates = _candidates;
        sort(candidates.begin(), candidates.end());
        dfs(target);
        return res;
    }
};
```
还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)

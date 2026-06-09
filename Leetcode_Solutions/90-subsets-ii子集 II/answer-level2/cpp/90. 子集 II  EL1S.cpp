78题是子集I，没有重复数字，本题有重复数字
考虑方式相似，不同的地方就是要去处理那些重复的数字

首先要去想的是：重复的数字在什么地方才能出现？
答：在已经出现过的地方才能出现，在没有出现过的地方只能出现那个领头的数字
因此，代码可以从78题修改至如下：
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        int start = 0;
        for(int i = 0; i < nums.size(); i++)
        {


            start = (i && nums[i] == nums[i - 1])?start:0;
            int len = res.size();
            for(int j = start; j < len; j++)
            {
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            start = len;
        }
        return res;
    }
};
```


第二种想法
我们去想一下，把重复的数字看成一个整体，然后想一下，它的可能性：都不出现，出现一个，出现两个...出现k个
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int same = 1;
            while(i + 1 < nums.size() && nums[i + 1] == nums[i])
            {
                same++;
                i++;
            }
            int len = res.size();
            for(int j = 0; j < len; j++)
            {
                auto tmp = res[j];
                for(int k = 0; k < same; k++)
                {
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
```

还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)

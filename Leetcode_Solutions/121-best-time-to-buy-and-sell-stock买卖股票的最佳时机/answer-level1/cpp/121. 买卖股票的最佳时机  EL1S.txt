要找一个值，减去前面最小的，那么就得到最大利润了
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int minval = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            int tmp = prices[i];
            prices[i] = tmp - minval;
            minval = min(minval, tmp);
            res = max(res, prices[i]);
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


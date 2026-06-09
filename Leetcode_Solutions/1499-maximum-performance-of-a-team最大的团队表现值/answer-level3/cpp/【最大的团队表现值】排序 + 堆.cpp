### 思路
1. 对 `speed` 和 `efficiency` 同步排序，按照效率降序
2. 遍历，对每一项数据
    21. 累加和 `sum` ，当超过 `k` 个的数据时，选最小的将其排除
    22. 使用优先队列来找到 `k` 个中最小的数据
    23. 效率的最低值就是当前项的效率
    24. 计算结果，注意这里不能取余
3. 返回最终结果时取余

### 图解
```
输入：n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
输出：60
```
<![图片.png](https://pic.leetcode-cn.com/a3b459b5c8401c57a2a5f4f74153b0e2a4df4f94255ef625307f2d3db5e514f4-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/aac68f0479d9293ae1ecbe54ee19bd89b6ba27d468873c40f51a9b20c98fc047-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/05ec205c48bfc9bb25ead54cef23f0aba4f0bdbfdf14b52b6fae44b404a818a8-%E5%9B%BE%E7%89%87.png)>


### 答题
```C++ []
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
{
    const int mod = 1000000007;

    vector<vector<int>> es;
    for (int i = 0; i < efficiency.size(); i++)
    {
        es.push_back({ efficiency[i], speed[i] });
    }
    sort(es.rbegin(), es.rend());

    long long ans = 0;
    long long sum = 0;
    long long eff = INT_MAX;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < es.size(); i++)
    {
        eff = es[i][0];
        sum += es[i][1];
        que.push(es[i][1]);
        if (--k < 0)
        {
            sum -= que.top();
            que.pop();
        }
        ans = max(ans, sum * eff);
    }
    return ans % mod;
}
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)



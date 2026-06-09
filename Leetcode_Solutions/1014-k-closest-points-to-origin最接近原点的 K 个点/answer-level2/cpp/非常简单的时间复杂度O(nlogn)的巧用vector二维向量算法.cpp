### 解题思路

![1.png](https://pic.leetcode-cn.com/9c46e85c505ba9284126e8681af0d3b29aaac46c66a81fe5f583a36a4b89a7d6-1.png)

### 代码

```cpp
class Solution
{
public:
    struct node//自定义struct用来保存dis便于排序
    {
        int r;
        int c;
        int dis;
    };
    static bool cmp(node a, node b)//自定义排序函数
    {
        return a.dis < b.dis;
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        vector<node> V;//用来保存要排序的node节点
        vector<vector<int>> vec;//存放结果的二维向量
        for (int i = 0; i < points.size(); i++)
        {
            node temp = {points[i][0], points[i][1], pow(points[i][0], 2) + pow(points[i][1], 2);
            V.push_back(temp);
        }
        sort(V.begin(), V.end(), cmp);
        for (int i = 0; i < K; i++)
        {
            vec.push_back({V[i].r, V[i].c});
        }
        return vec;
    }
};
```
最近疫情期间闲得无聊来刷题，纯粹为了玩，写完的题我会post到我的博客上，欢迎大家赏光~
[https://mrsuncodes.github.io/](https://mrsuncodes.github.io/)
### 思路
1. 看好题目描述，搞清楚逻辑关系，模拟即可
2. 这是一个 2 行 n 列的二进制矩阵，说明数值只有 0/1 两种
3. 第 0 行的元素之和为 upper，所以这个是第 0 行的 sum
4. 第 1 行的元素之和为 lower，所以这个是第 1 行的 sum
5. 第 i 列（从 0 开始编号）的元素之和为 colsum[i] ，所以各个列的 sum 也有了
6. 总结一下，就是知道了横着的和，竖着的和，又知道只可能是 0 或者 1 ，求符合条件的一种

那么，
1. 每列之和只有 3 种可能，即 0 1 2
2. 2 不用说了，就是上下都是 1
3. 0 也不用说了吧，上下都是 0
4. 对于 1 来说，要么上要么下
   1. 如果后边还有 2 ，那么他后面需要一个 1 。先遍历一遍记录有几个 2
   2. 根据 upper 和 lower 的计数，除了后面 2 的情况还有富余的话，就可以分配
   3. 否则就是不符合，返回空数组
5. 因为分配的时候能确定正确与否，所以不用回溯，不用贪心，就模拟即可

### 答题
```C++
vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &c : colsum)
    {
        cnt0 += (c == 0);
        cnt1 += (c == 1);
        cnt2 += (c == 2);
    }
    if (upper + lower != cnt1 + cnt2 * 2) return {};
    if (upper > colsum.size() - cnt0) return {};
    if (lower > colsum.size() - cnt0) return {};

    vector<vector<int>> ans(2, vector<int>());
    for (auto &c : colsum)
    {
        if (c == 0)
        {
            ans[0].push_back(0);
            ans[1].push_back(0);
        }
        else if (c == 2)
        {
            ans[0].push_back(1);
            ans[1].push_back(1);
            cnt2--;
            upper--;
            lower--;
        }
        else
        {
            if (upper > cnt2)
            {
                ans[0].push_back(1);
                ans[1].push_back(0);
                upper--;
            }
            else if (lower > cnt2)
            {
                ans[0].push_back(0);
                ans[1].push_back(1);
                lower--;
            }
            else 
            {
                return {};
            }
        }
    }
    return ans;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


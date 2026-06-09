### 思路
1. 使用 bfs
2. 根据 `j 满足：arr[i] == arr[j] 且 i != j` 这个条件
3. 需要对数据进行处理，使用 `unordered_map<int, vector<int>> same` 把值相同的索引整理到一起
4. bfs 时，先向左向右，再向 `same` 里的跳

### 用例
```
Input: [7,7,7, ... 7,11] (4999 个 7)
Output: 2
```
没想那么多，结果这个用例超时了。  
不能让 bfs 里要把 `same` 全都跳一遍，所以要把连续的 7 中间都删掉。

### 答题
```C++
int minJumps(vector<int>& arr) 
{
    unordered_map<int, vector<int>> same;
    int pre_i = 0;
    int pre_val = arr[0];
    same[pre_val].push_back(pre_i);
    for (size_t i = 1; i < arr.size(); i++)
    {
        int val = arr[i];
        if (val == pre_val && i != arr.size() - 1)
        {
            pre_i = i;
            continue;
        }
        same[pre_val].push_back(pre_i);
        pre_i = i;
        pre_val = val;
        same[pre_val].push_back(pre_i);
    }

    vector<int> vi(arr.size(), 0);
    queue<int> que;
    que.push(0);
    vi[0] = 1;

    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        if (q == arr.size() - 1) break;

        if (q != 0 && vi[q - 1] == 0)
        {
            que.push(q - 1);
            vi[q - 1] = vi[q] + 1;
        }
        if (q != arr.size() - 1 && vi[q + 1] == 0)
        {
            que.push(q + 1);
            vi[q + 1] = vi[q] + 1;
        }
        auto s = same[arr[q]];
        for (size_t i = s.size() - 1; i < s.size(); i--)
        {
            if (vi[s[i]] != 0) continue;
            que.push(s[i]);
            vi[s[i]] = vi[q] + 1;
        }
    }

    return vi[arr.size() - 1] - 1;
}
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


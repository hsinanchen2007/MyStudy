
# 解法一
看了题解都好复杂，涉及到欧拉图、欧拉路径的，用的是Hierholzer算法。
一开始看不懂题解，然后按照自己的想法写了一遍也通过了，不知道这种方法是否合理，大家帮我看一下。


思路：
- 怎么记录路径？记录路径有两种方法，
    - 方法一是先记录当前路径，然后将路径传到下一层递归里；
    - 方法二是是先进到递归里，一直递归到尽头，从尽头把路径一个个返回来。
    这里采用的是第一种方法。
- 怎么判断自然排序？一开始写了个函数判断两个路径排序，后来改用map存站点，C++ map自带升序排序功能。
- 何时算找到一条路径？用count计数path遍历的边数，若count等于所有边数数目，则认为找到了一条能遍历完所有边的路径。


```cpp
class Solution {
public:
    // 这里用map，内部自动按照string升序排列了，所以先找到的一定是自然排序最小的路径
    typedef unordered_map<string, map<string, int>> adjacent;
    vector<string> min_path;
    int max_count;
    bool dfs(adjacent &adj, string airport, int count){
        min_path.push_back(airport);
        count++;
        // 达到路径数就表示找到了一条合理路径，返回true表示已经找到了一条路径
        // 后面不用再遍历了
        if(count == max_count)
            return true;

        for(auto &[next, number] : adj[airport]){
            if(0 >= number)
                continue;
            --number;
            if(dfs(adj, next, count))
                return true;
            ++number; // 回溯

        }
        min_path.pop_back(); // 回溯
        return false;

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.size() == 1)
            return tickets[0];
        // 初始化邻接表，因为存在多张相同机票的情况，所以邻接表中还记录了从from到to的机票数
        adjacent adj;
        for(auto & t : tickets){
            if(adj.find(t[0]) == adj.end())
                adj[t[0]] = map<string, int>();
            if(adj[t[0]].find(t[1]) == adj[t[0]].end())
                adj[t[0]][t[1]] = 0;
            adj[t[0]][t[1]]++;
        }
        // 路径数，达到路径数就表示找到了一条合理路径
        max_count = tickets.size();
        dfs(adj, "JFK", -1);
        return min_path;
    }
};
```

![snipaste_20200401_173854.png](https://pic.leetcode-cn.com/b494a1529c930a1f59702f3b45cded6584cf383b31e903612d01badc9f8e75f7-snipaste_20200401_173854.png)




# 解法二
后来我补了下`Hierholzer算法`，大概理解了`Hierholzer算法`，下面是我的理解，不知道对不对。
个人觉得Hierholzer算法就是证明了一点：`当存在欧拉路径时，从合理的起始点无脑dfs遍历，得到的路径一定是欧拉路径。`暂且不管结论是怎么来的，我们可以想象，如果这个结论成立，那我岂不是无脑dfs就行了？答案是在本题确实是这样的。（[如果大家想了解具体原理或一些细节，可以看这里](https://blog.csdn.net/a435262767/article/details/105253850)，博文里还给出了一些参考链接）
因为题目规定了一定有欧拉路径，并且起点一定是JFK（所以这个起始点一定是合理的），所以根据Hierholzer算法，可以无脑dfs。
下面是代码，把注释去掉就几行。
```cpp
class Solution {
public:
    // 这里用map，内部自动按照string升序排列了，所以先找到的一定是自然排序最小的路径
    typedef unordered_map<string, map<string, int>> adjacent;// 记录从from到to的机票数
    vector<string> min_path;
    bool dfs(adjacent &adj, string airport){
        // 无脑dfs遍历邻居，同时遍历过的边标记已遍历
        for(auto &[next, number] : adj[airport]){
            // 若从airport到next的机票没有了，则遍历下一个
            if(0 >= number)
                continue;
            --number;// 从airport到next的机票数减一
            dfs(adj, next);
        }
        // 终点是没有相邻边的点
        // 当删除终点后，终点前的点也没有相邻边了，变成新的终点
        // 运行到这里，当前airport一定没有可遍历的相邻边了，则它是此时的终点
        min_path.push_back(airport);
        return true;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 初始化邻接表，因为存在多张相同机票的情况，所以邻接表中还记录了从from到to的机票数
        adjacent adj;
        for(auto & t : tickets){
            adj[t[0]][t[1]]++;
        }
        // Hierholzer算法，dfs无脑遍历
        dfs(adj, "JFK");

        // Hierholzer算法得到结果为终点到起点的路径，需要反转才是题目所要求的结果
        std::reverse(min_path.begin(), min_path.end());
        return min_path;
    }
};
```
![snipaste_20200401_191136.png](https://pic.leetcode-cn.com/a4752d32c11b943f8a85b271dbf18590447942c3f3c71e098b517995974af93e-snipaste_20200401_191136.png)


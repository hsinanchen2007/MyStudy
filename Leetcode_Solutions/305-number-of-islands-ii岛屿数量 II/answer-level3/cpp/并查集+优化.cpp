基本思路还是每次addLand后使用并查集求连通图数量。
优化：
1. 只对添加的陆地和周围（上下左右）的陆地进行merge操作；
2. merge操作返回是否成功：
- 第一次一定成功，因为新添加的陆地不属于任何一座岛；
- 之后的每次成功意味着原先不相连的两个岛被连接；
- 基于这个优化，计数时不必遍历寻找祖先节点，保留上次的小岛数量count，先++count，每次merge成功--count即可；

下附代码：
```
class Solution {
    public:
        vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
            vector<int> res;
            if(positions.empty())
                return res;
            
            vector<vector<int>> myMap(m, vector<int>(n, 0));
            pre = new int[m * n];
            for(int i = 0; i < m * n; ++i)
                pre[i] = i;
            //测试数据里竟然有重复数据
            unordered_map<int, bool> checker;
            
            int count = 0;
            for(auto tmp : positions){
                if(checker.find(tmp[0] * n + tmp[1]) != checker.end()){
                    res.push_back(count);
                    continue;
                }
                else
                    checker[tmp[0] * n + tmp[1]] = true;

                myMap[tmp[0]][tmp[1]] = 1;

                ++count;
                if(tmp[0] - 1 >= 0 && myMap[tmp[0] - 1][tmp[1]])
                    if(merge(tmp[0] * n + tmp[1], (tmp[0] - 1) * n + tmp[1]))
                        --count;                
                if(tmp[0] + 1 < m && myMap[tmp[0] + 1][tmp[1]])
                    if(merge(tmp[0] * n + tmp[1], (tmp[0] + 1) * n + tmp[1]))
                        --count;                
                if(tmp[1] - 1 >= 0 && myMap[tmp[0]][tmp[1] - 1])
                    if(merge(tmp[0] * n + tmp[1], tmp[0] * n + tmp[1] - 1))
                        --count;                
                if(tmp[1] + 1 < n && myMap[tmp[0]][tmp[1] + 1])
                    if(merge(tmp[0] * n + tmp[1], tmp[0] * n + tmp[1] + 1))
                        --count;
                
                res.push_back(count);
            }
            
            return res;
        }
        
    private:
        int *pre = nullptr;
        
        bool merge(int i1, int i2){
            int p1 = getp(i1);
            int p2 = getp(i2);
            if(p1 != p2){
                pre[p1] = p2;
                return true;
            }
            return false;
        }
        
        int getp(int cur){
            while(cur != pre[cur])
                cur = pre[cur];
            return cur;
        }
};
```

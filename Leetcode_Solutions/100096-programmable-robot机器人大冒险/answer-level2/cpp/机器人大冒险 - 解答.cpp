**时间：**$O(m+n)$，其中 $m =$ `command.size()`，$n =$ `obstacles.size()`
**空间：**$O(m)$

**思路：**
机器人会无限循环地按照 `command` 中的指令进行移动，我们可以记录下机器人在一次循环中所经过的坐标，后续循环中到达的坐标都可以推测出来。

例如，`command = 'RRU'`，则在一次循环中机器人会经过 $(0,0),(1,0),(2,0),(2,1)$ 这四个点。在第二次循环中它会经过 $(3,1),(4,1),(4,2)$ 这三个点。在第三次循环中他会经过 $(5,2),(6,2),(6,3)$ 这三个点……

已知机器人在第一次循环中走过的所有点，和向右移动的总距离 $xx$，和向上移动的总距离 $yy$。给出任意一个点 $(m,n)$，如何判断这个点是否在机器人的运动轨迹中？

我们可以计算出从原点到 $(m,n)$ 需要走多少个循环，也就是横坐标循环的次数与纵坐标循环的次数的较小值：`circle = min(m/xx,n/yy)`。然后我们就可以得到点 $(m,n)$ 相当于第一次循环中的哪个点。如果这个点在第一次循环的轨迹中，那么机器人一定可以到达这个点。反之则不能到达。

**在本题中，机器人能够完好地到达终点需要满足两个条件：**
1. 终点一定在机器人运动的轨迹中（一定在第一次循环的轨迹中）
2. 所有障碍物的坐标都不在机器人运动的轨迹中（一定不在第一次循环的轨迹中）

**如何存储机器人的轨迹坐标？**
考虑到 $0 <= x <= 1e9$，$0 <= y <= 1e9$，可以将所有点的横坐标左移 $30$ 位，和纵坐标做按位或运算，再存储到哈希集合中。接下来只需按照两个条件一一查找相应的坐标即可。

```cpp [-C++]
bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
    unordered_set<long> s;
    int xx = 0,yy = 0;
    s.insert(0);
    for(auto c : command){
        if(c == 'U') yy++;
        else if(c == 'R')xx++;
        s.insert(((long)xx << 30) | yy);
    }
      
    int circle = min(x/xx,y/yy);
    if(s.count(((long)(x-circle*xx) << 30) | (y-circle*yy)) == 0) return false;
    
    for(auto v: obstacles){
        if(v.size() != 2) continue;
        if(v[0] > x || v[1] > y) continue;
        circle = min(v[0]/xx,v[1]/yy);
        if(s.count(((long)(v[0]-circle*xx) << 30) | (v[1]-circle * yy))) return false;
    }
    return true;
}
```

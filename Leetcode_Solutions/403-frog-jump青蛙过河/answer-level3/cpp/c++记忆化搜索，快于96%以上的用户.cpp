## 状态表示
青蛙在过河的过程中，存在两个状态，第一个是青蛙所在坐标$x$，另一个是青蛙上次跳动到这里用的跳跃距离（后面称为步数）$y$。
其中起始状态为$(1,1)$，表示青蛙由坐$0$跳了$1$步到达坐标$1$。终点坐标为$(stones.back(),...)$，只要到达$stones.back()$这个坐标就可以了，步数为几都可以。由于每次跳跃步数只能$+1$，石头数量最多为1000，而且只能往前跳，所以这个步数的可能值位于$[1,1001]$内。

## 状态转移
由状态$(x,y)$的状态的转移有3种方式：
1. 向前跳y步，到达$(x+y,y)$
2. 向前跳y-1步，到达$(x+y-1,y-1)$
3. 向前跳y+1步，到达$(x+y+1,y+1)$

同样，可以计算状态$(x,y)$可以由3种状态转移过来：
1. $(x-y,y)$，向前跳$y$步，到达$(x,y)$
2. $(x-y,y+1)$，向前跳$y$步，到达$(x,y)$
3. $(x-y,y-1)$，向前跳$y$步，到达$(x,y)$
由于反着计算比较好写(字母数比较少233)，所以后面采用从终点往回搜索的方式。(其实是因为有一个样例会爆int，反着写可以不用这个判断)

## 状态搜索
知道了状态表示和状态转移方式，可以直接采用深度优先遍历的方式对于整个搜索空间进行暴力搜索。其中有一些边界条件需要注意：
1. 位置坐标范围集合 $\left \{x|x\in stones \right \}$
2. 步数范围$[1,1001]$

由于搜索过程中会有大量的重复状态，因此可以使用记忆化搜索来加快搜索速度。

## 一些小技巧
1. 将*stones*放进`unordered_set<int>`内，加快判断速度
2. 将两个*int* 类型组合成一个`long long`类型，以便使用`unordered_map<long long,bool>`来存储搜索过的状态变量`long long t = (long long)x<<32|y;`


# 完整代码

```
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> h;
        for(auto x:stones) h.insert(x);
        unordered_map<long long, bool> memo;
        
        function<bool(int,int)> dfs = [&] (int x, int y) {
            if(y<=0 || !h.count(x)) return false;
            if(x==1&&y==1) return true;
            
            long long t = (long long)x<<32|y;
            if(memo.count(t)) return memo[t];
            
            if(dfs(x-y,y)||dfs(x-y,y-1)||dfs(x-y,y+1))
                return memo[t] = true;
            return memo[t] = false;
        };
        
        for(int i = 1 ; i <= 1001 ; i ++)
            if(dfs(stones.back(),i))
                return true;
        return false;
    }
};
```

当然用map套map也是可以的，不过比前面的慢一点
```
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> h;
        for(auto x:stones) h.insert(x);
        
        unordered_map<int,unordered_map<int,bool>> memo;
        
        function<bool(int,int)> dfs = [&] (int x, int y) {
            if(y<=0 || !h.count(x)) return false;
            if(x==1&&y==1) return true;
            
            if(memo.count(x) && memo[x].count(y)) return memo[x][y];
            
            if(dfs(x-y,y)||dfs(x-y,y-1)||dfs(x-y,y+1))
                return memo[x][y] = true;
            return memo[x][y] = false;
        };
        
        for(int i = 1 ; i <= 1001 ; i ++)
            if(dfs(stones.back(),i))
                return true;
        return false;
    }
};
```
### 解题思路
1. 一条自顶向下的、穿过最少砖块的垂线 ： 
穿过最少砖块即找到某一位置，满足当前前缀和相同的行数最多
最少砖块数 = 行数 - 前缀和相同的最大行数

[[1,2,2,1],
[3,1,2],
[1,3,2],
[2,4],
[3,1,2],
[1,3,1,1]]

不能沿着墙的两个垂直边缘之一画线 : 不记录一行砖的长度
第0行 sum 1 3 5 
第1行 sum 3 4 
第2行 sum 1 4 
第3行 sum 2 
第4行 sum 3 4 
第5行 sum 1 4 5 
4的个数最多：有4个
穿过最少砖块数 = 行数 - 4 （个）

2. hash表
`unordered_map<int,int> hash;` key : sum , value : sum 出现的次数

3. 找前缀和相同的最大行数
可以每次在记录 sum 的时候记录最大 value
发现：全部记录完再使用大根堆找最大值会更快 

### 代码
**1. 前缀和最多的出现次数  hash  84ms**
```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int height = wall.size(),res = 0;
        unordered_map<int,int> hash;
        for(int i = 0;i < height;i ++){
            for(int j = 1,sum = 0;j < wall[i].size();j ++){
                sum += wall[i][j - 1];
                hash[sum] ++;
                res = max(res,hash[sum]);
            }
        }
        return height - res;
    }
};
```

**2. 排序时使用大根堆 52ms **
```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size() == 0 || wall[0].size() == 0) return 0;
        int height = wall.size();
        unordered_map<int,int> hash;
        for(int i = 0;i < height;i ++)
            for(int j = 1,sum = 0;j < wall[i].size();j ++){
                sum += wall[i][j - 1];
                hash[sum] ++;
            }
        priority_queue<pair<int,int>> heap;
        for(auto it : hash)
            heap.push({it.second,it.first});
        if(heap.empty()) return height;
        return height - heap.top().first;
    }
};
```

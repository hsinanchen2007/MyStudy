### [1345. 跳跃游戏 IV](https://leetcode-cn.com/problems/jump-game-iv/)

#### 题解

  + 将所有value相同的元素的下标统计在一起
  + 利用$unordered\_map$构造$<key:value> = <数组值:数组下标集合>的键值对$
  + $unordered\_map$的是基于$hash$实现无序映射，其查找和删除的复杂度大部分情况下为$O(1)$，优于$map$的$O(logn)$, 但相较于$map$，其空间占用更多。
  + 利用$bfs$进行最短距离搜索，由于所有同值的下标只会访问一次，所以可以在扩展后直接删除。
  + 时间复杂度为$O(n)$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码
```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
      unordered_map<int, vector<int>> mp;
      for(int i = 0; i < arr.size(); i++)
          mp[arr[i]].push_back(i);
      int* dis = new int[arr.size()];
      for(int i = 0; i < arr.size(); i++)
          dis[i] = -1;
      queue<int> q;
      q.push(0);
      dis[0] = 0;
      while(!q.empty())
      {
        int t = q.front();
        q.pop();
        if(t == arr.size()-1) return dis[t];
        if(t-1 >= 0) {if(dis[t-1] == -1) {dis[t-1] = dis[t] + 1; q.push(t-1);}}
        if(t+1 < arr.size()) {if(dis[t+1] == -1){dis[t+1] = dis[t] + 1; q.push(t+1);}}
        for(int i = 0; i < mp[arr[t]].size(); i++)
        {
          int tmp = mp[arr[t]][i];
          if(dis[tmp] == -1)
          {
            dis[tmp] = dis[t] + 1;
            q.push(tmp);
          }
        }
        mp.erase(arr[t]);
      }
      return -1;
    }
};
```

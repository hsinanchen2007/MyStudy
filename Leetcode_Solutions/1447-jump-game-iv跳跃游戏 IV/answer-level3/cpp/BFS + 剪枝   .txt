## [Leetcode 1345. 跳跃游戏 IV](https://leetcode-cn.com/problems/jump-game-iv/)
## 题意：
给一个一维的数组，你从下标0开始出发，有三种操作：每次可以向左，右移动一位，或者移动到与自己数值相同的位置。

## 思路:
这类搜索求最短步数的解法是典型的bfs，注意这题数据的特殊性，裸bfs会超时。 
这是因为第三个操作枚举所有相同数值的位置时候，如果出现很多
相同值的数值，光枚举相同值时间复杂度会近似O(n)，整体就变成O(n^2)。

这一步枚举，可以把**连续出现相同值的区间只保留左右两个端点**，起到搜索剪枝的作用。

## 代码:
python
```python
class Solution:
    def minJumps(self, arr) -> int:
        import collections
        n = len(arr)
        if n  == 1: return 0
        poss = collections.defaultdict(list)
        for index, value in enumerate(arr):
            if (index and arr[index]!= arr[index-1] or
                    (index < n-1 and arr[index]!=arr[index + 1])): # 剪枝
                poss[value] .append(index)
        que= collections.deque([(0,0)])
        vis = set([0])
        while que:
            pos, cur  = que.popleft()
            for nxt in poss[arr[pos]] + [pos+1 ,pos -1]:
                if nxt == n -1: return cur +1
                if 0 < nxt < n-1 and nxt not in vis:
                    que.append((nxt , cur+1))
                    vis.add(nxt)
```

c++
```c++
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> pos;
        for(int i =0 ;i<n;i++){
            if((i>0&&arr[i]!=arr[i-1])||(i<n-1&&arr[i]!=arr[i+1])){
                pos[arr[i]].push_back(i);
            }
        }
        queue<pair<int,int> > que;
        que.push(make_pair(0 ,0));
        set<int> vis;
        vis.insert(0);
        int ans =0 ;
        bool flag = false;
        while(!que.empty()){
            int p = que.front().first, cur = que.front().second;
            que.pop();
            for(int i=0;i<pos[arr[p]].size();i++){
                int nxt = pos[arr[p]][i];
                if((nxt == n-1)||(p+1 == n-1)){
                        ans = cur + 1;
                        flag = true;
                        break;
                }
                if(nxt>1&&nxt<n&&vis.count(nxt)==0){
                    que.push(make_pair(nxt, cur+1));
                    vis.insert(nxt);
                }
            }
            if(flag) break;
            if(p+1>0&&p+1<n&&vis.count(p+1)==0){
                que.push(make_pair(p+1, cur+1));
                vis.insert(p+1);
            }
            if(p-1>0&&p-1<n&&vis.count(p-1)==0){
                que.push(make_pair(p-1, cur+1));
                vis.insert(p-1);
            }
        }
        return ans;
    }
};
```

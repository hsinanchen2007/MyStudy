### 解题思路
此处撰写解题思路
机器人从原点开始行走，从每一个当前的点开始有四个方向可以选择，且能够到达的方格一定由上一个到达的方格走到。因此可以将可以走到的方格存储到队列中，跟据当前队列顶上的元素搜索可以到达的方格，当队列为空时，搜索完毕。
### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int ans=1;
        unordered_set<string> s;
        queue<pair<int, int>> q;
        q.emplace(make_pair(0,0));
        s.emplace("0+0");
        int i=0,j=0;
        while(!q.empty()){
            i =q.front().first;
            j =q.front().second;
            q.pop();
            if(i-1>=0 && s.find(to_string(i-1)+'+'+to_string(j)) ==s.end() && get_sum(i-1)+get_sum(j)<=k){
                q.emplace(make_pair(i-1,j));
                s.emplace(to_string(i-1)+'+'+to_string(j));
                ans++;
            }
            if(i+1<m && s.find(to_string(i+1)+'+'+to_string(j)) ==s.end() && get_sum(i+1)+get_sum(j)<=k){
                q.emplace(make_pair(i+1,j));
                s.emplace(to_string(i+1)+'+'+to_string(j));
                ans++;
            }
            if(j-1>=0 && s.find(to_string(i)+'+'+to_string(j-1)) ==s.end() &&get_sum(i)+get_sum(j-1)<=k){
                q.emplace(make_pair(i,j-1));
                s.emplace(to_string(i)+'+'+to_string(j-1));
                ans++;
            }
            if(j+1<n && s.find(to_string(i)+'+'+to_string(j+1))== s.end() &&get_sum(i)+get_sum(j+1)<=k){
                q.emplace(make_pair(i,j+1));
                s.emplace(to_string(i)+'+'+to_string(j+1));
                ans++;
            }
        }
        return ans;

    }
    int get_sum(int num){
        int sum=0;
        string s = to_string(num);
        int times = s.length();
        for(int i=0;i<times;i++){
            sum += s.at(i)-'0';
        }
        return sum;
    }
};
```
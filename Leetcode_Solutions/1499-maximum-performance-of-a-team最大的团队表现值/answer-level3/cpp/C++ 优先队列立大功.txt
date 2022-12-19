### 解题思路
维护一个有K个最大值的队列就可以了,ok，起飞！

### 代码

```cpp
const int MAXN = 1E5+5;
const int INF = 1e9+7;
struct Node{
    int s,e;
}node[MAXN];
/*
效率高的放前面，因为我们要找到效率最低的
*/
bool cmp(const Node &n1,const Node&n2){
    return n1.e>n2.e;
}
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int len = n;
        for(int i = 0;i<len;i++){
            node[i].s = speed[i];
            node[i].e = efficiency[i];
        }
        sort(node,node+len,cmp);
        priority_queue<long long> que;while(!que.empty()) que.pop();
        long long  sums = 0;
        long long  ans = INT_MIN;
        for(int i = 0;i<len;i++){
            sums += node[i].s;
            que.push(-node[i].s);//大变小，小变大，便于减去小的
            while(que.size()>k){
                sums += que.top();que.pop();
            }
            long long tempans = 1ll * node[i].e * sums ;
            ans = max(tempans,ans);
        }
        return ans%INF;
    }
};
```
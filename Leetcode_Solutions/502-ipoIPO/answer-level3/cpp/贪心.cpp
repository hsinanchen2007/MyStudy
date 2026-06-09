### 解题思路
定义两个优先队列：一个按利润从高到低q1，一个按成本从低到高q2，先将所有数据存入q2。要求最大利润那么就是每一步都要投资当前资金下能投资的利润最大的项目。
- 每次投资时将q2中成本小于等于资金W的项目压入q1，然后弹出q2中利润最大的项目，更新资金W。
- 后面再投资时前面压入q1的项目的成本肯定也是小于现有资金的，因为资金只增不减。

### 代码

```cpp
class Solution {
    struct node{
        int p,c;
    };
    struct maxget{
        bool operator () (node a,node b){
            return a.p<b.p;
        }
    };
    struct mincost{
        bool operator () (node a,node b){
            return a.c>b.c;
        }
    };
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<node,vector<node>,maxget>q1;
        priority_queue<node,vector<node>,mincost>q2;
        for(int i=0;i<Profits.size();i++){
            q2.push({Profits[i],Capital[i]});
        }
        for(int i=0;i<k;i++){
            while(!q2.empty()&&q2.top().c<=W){
                q1.push(q2.top());
                q2.pop();
            }
            if(q1.empty()) break;
            W+=q1.top().p;
            q1.pop();
        }
        return W;
    }
};
```
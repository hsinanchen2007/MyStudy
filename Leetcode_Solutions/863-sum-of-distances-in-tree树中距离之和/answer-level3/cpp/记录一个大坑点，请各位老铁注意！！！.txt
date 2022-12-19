### 解题思路
此处撰写解题思路
**坑点**:通过调用函数每一个节点的子节点数量和计算每个节点的花费时，传入的孩子节点参数必须以传引用的方式！！！
因为这两个函数通过递归的方式逐步求解问题，当节点数量增多时，过程中会多次的调用函数自身，孩子节点参数的空间容量会达到o(n*n)，创建内存的时间也会因此而大大增加！引用相当于是传递的地址，需要开辟的内存大小为地址的内存大小。而值传递传递kid开辟的是这个向量的内存，远远大于地址的内存。
根据 ans(A) = sum(A) + sum(B) + cnt(B); ans(B) = sum(B) + sum(A) + cnt(A);两个式子可以推出ans(a)+count(a)=ans(b)+count(b);
1、使用bfs求出树中各个节点的孩子节点
2、求出每个节点的子节点数量纪录为countv
3、计算根节点的ans[0]
4、根据当前节点的周边节点来计算ans
### 代码

```cpp
void countnode(vector<vector<int>> &kid,vector<vector<int>> matric,int N)
{
    queue<int> q;vector<int> visit(N,0);
    q.push(0);visit[0]=1;int count=1;
    while(count<N)
    {
        int width=q.size();
        for(int i=0;i<width;++i)
        {
            int temp=q.front();
            q.pop();
            for(auto j:matric[temp])
            {
                if(visit[j]==0)
                {
                    ++count;
                    visit[j]=1;
                    kid[temp].push_back(j);
                    q.push(j);
                }
            }
        }
    }
}
void countv(int i,vector<int> &v,vector<vector<int>> &kid)//此处kid必须使用引用的方式传入。
{
    if(kid[i].empty())
    v[i]=0;
    else
    {
        int c=0;
        for(auto it:kid[i])
        {
            countv(it,v,kid);
            c+=v[it]+1;
        }
        v[i]=c;
    }
}
    int bfs(int node,int cost,vector<vector<int>> &kid)
    {
        int total = cost;
        if(kid[node].empty())
        {
            return total;
        }
        else
        {
            for(auto i:kid[node])
            {
                total += bfs(i,cost+1,kid);
            }
            return total;
        } 
    }
    void countansall(vector<int> &res,vector<vector<int>> &kid,int node,vector<int> v,int N)
    {
        if(kid[node].size()==0)
        return;
        else
        {
            for(auto it:kid[node])
            {
                res[it]=res[node]+(N-1-v[it])-(1+v[it]);
                countansall(res,kid,it,v,N);
            }
        }
    }
class Solution{
    public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)
    {
        vector<vector<int>> nearby(N);
        for(auto edge:edges)
        {
            nearby[edge[0]].push_back(edge[1]);
            nearby[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> kid(N);
        vector<int> v(N,0);
        int x,y,temp,i,j,count,width,k;
        countnode(kid,nearby,N);
        countv(0,v,kid);
        vector<int> res(N,0);
        res[0]=bfs(0,0,kid);
        countansall(res,kid,0,v,N);
        return res;
    }
};
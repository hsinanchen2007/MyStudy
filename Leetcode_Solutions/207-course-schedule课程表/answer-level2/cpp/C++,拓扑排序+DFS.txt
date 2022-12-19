解法一：拓扑排序
```
class Solution {
public:
//检验是否存在环，，
//图中是否存在环有两种解法：1.拓扑排序。2.DFS
//拓扑排序算法只需要判断是否存在环就可以啦，别的不需要考虑的。。。
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,set<int>>mp;
        vector<int>indegree(numCourses+1,0);
        for(auto v:prerequisites){
            int a=v[1];
            int b=v[0];
            mp[a].insert(b);//构建a-->b的有向图
            ++indegree[b];//初始化入度
        }
        //拓扑排序，采用的是队列，存放的是入度为0的点，即准备释放的点。
        queue<int>que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int v=que.front();
            que.pop();
            ++count;
            //下面就是将出队之后，与那个点相邻的点入度减少一个，其中入度为0的点，入队列
            auto x=mp[v];//x是一个数组
            for(auto t:x){
                indegree[t]--;
                if(indegree[t]==0){
                    que.push(t);
                }
            }

        }
        return count==numCourses;
    }
};
```
另外一种使用vector的解法：
```
class Solution {
public:
//拓扑排序写法
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>ans(numCourses,vector<int>());
        vector<int>indegree(numCourses);
        if(prerequisites.size()==0)return true;
        for(int i=0;i<prerequisites.size();i++){
            ans.push_back(vector<int>());
        }
        for(auto v:prerequisites){
            ans[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int>que;
        int count=0;
        for(int i=0;i<numCourses;i++){
            //cout<<indegree[i]<<endl;
            if(indegree[i]==0){
                que.push(i);
                //count++;
            }
        }
        
        while(!que.empty()){
            int top=que.front();
            que.pop();
            count++;
            // for(auto v:ans[top]){
            //     indegree[v]--;
            //     if(indegree[v]==0){
            //         que.push(v); 
            //     }
            // }
            if(count==numCourses)return true;
            cout<<count<<endl;
            for(int i=0;i<ans[top].size();i++){
                indegree[ans[top][i]]--;
                if(indegree[ans[top][i]]==0){
                    que.push(ans[top][i]);
                }
            }
        }
       // cout<<count<<endl;
        return count==numCourses;
    }
};
```
方法二：DFS
```
const int maxn=1000050;
class Solution {
public:
//DFS，模板题
    vector<int>ans[maxn];//定义一个二维数组，也可以下面这种定义方法：
    //vector<vector<int>>ans(numCourses,vector<int>());
    //vector<int>vis(maxn);//表示的是是否访问过,初始化-1，表示没有访问过
    bool dfs(int x,vector<int>&vis){
        vis[x]=0;//表示当前这个节点已近访问过了。
        bool ret=true;
        // for(int i=0;i<ans[x].size();i++){
        //     if(vis[ans[x][i]]==0)return false;
        //     if(vis[ans[x][i]]==-1)ret=ret&&dfs(ans[x][i]);
        // }
        for(auto v:ans[x]){
            if(vis[v]==0)return false;
            if(vis[v]==-1)ret=ret&&dfs(v,vis);
        }
        vis[x]=-1;//表示以这个点出发的所有能够遍历的点已经遍历完了。。这个点出发不存在环啦。。。
        return ret;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //vector<int>ans[numCourses];//定义一个二维数组，也可以下面这种定义方法：
        //vector<vector<int>>ans(numCourses,vector<int>());
        vector<int>vis(numCourses,-1);//表示的是是否访问过,初始化-1，表示没有访问过
        // for(int i=0;i<numCourses;i++){
        //     vis[i]=-1;
        //     ans[i].clear();
        // }
        // for(int i=0;i<prerequisites.size();i++){
        //     ans[prerequisites[i][0]].push_back(prerequisites[i][1]);
        // }
        for(auto v:prerequisites){
            ans[v[1]].push_back(v[0]);
        }
        bool ret=true;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==-1){
                ret=ret&&dfs(i,vis);
            }
        }
        return ret;
    }
};
```

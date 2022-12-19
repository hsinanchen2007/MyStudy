我们定义如果A[i]+A[j]是完全平方数时，则顶点i到顶点j是联通的。我们可以根据这个构建一张图。
我们的答案是从所有顶点遍历图中全部顶点一次且仅一次的路径数。
我们可以用dfs做到每个顶点的遍历，通过是否访问了全部顶点来判断该路径是否为答案的一个。
**关键在于如何去重。**
例如 [2,2,2]的输入。如果没有去重，我们的答案是3。
通过观察可以发现:
**1. 当我们把点i作为起点开始dfs的时候，如果当前点i对应的值A[i]dfs过了，我们就没必要再次对其dfs了。我们可以用hash标记做到去重。
2. 当我们在dfs找路径的时候，例如以i为起点，找到了j为终点这条路径。我们再次以i起点，又找到k为终点这条路径。如果A[j]==A[k] ，显然这是一条重复的路径。我们可以用set做到去重。**
```
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int g[12][12], ans = 0;
    void dfs(int i, int size, vector<bool> &vis, vector<int>& A){
        if(size == 0){
            ++ans;
            return ;
        }
        set<int> s;
        for(int j = 0; j < A.size(); ++j){
            if(g[i][j] == 1 && vis[j] == false && s.find(A[j]) == s.end()){
                vis[j] = true;
                dfs(j,size - 1, vis, A);
                vis[j] = false;
                s.insert(A[j]);
            }
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        vector<bool> vis(n);
        unordered_map<int, bool> ump;
        memset(g,0,sizeof(g));
        for(int i = 0; i < n; ++i){
        	ump[A[i]] = true;
            for(int j = i + 1; j < n; ++j){
                int tmp = sqrt(A[i] + A[j]);
                if(tmp * tmp == (A[i] + A[j])){
                    g[i][j] = 1;
                    g[j][i] = 1;
                }
            }
        }
        for(int i = 0; i < n; ++i){
        	if(ump[A[i]] == true){
        		ump[A[i]] = false;
        		vis.assign(n, false);
            	vis[i] = true;
            	dfs(i, n - 1, vis, A);	
        	}
        }
        return ans;
    }
};
```

先广度优先得到了离当前节点最远的节点，再深度优先搜索到最长路径。然后得到中间的一个点或者两个点(对应最长路径分别为奇数或者偶数的情况)
```
class Solution {// 找到最长的边，并且取最长边的中点就可以了
public:    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        graph = vector<vector<int>>(n);
        for(auto edge : edges){//初始化邻接表
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        visited = vector<int>(n, 0);
        path = vector<int>(n, 0);
        for(int i = 0; i < path.size(); i++)
            path[i] = i;

        int farNode = getFarNode(0);
        visited = vector<int>(n, 0);
        buildAnswer(farNode);

        while(farNode != path[farNode]){
            answer.push_back(farNode);
            farNode = path[farNode];
        }
        answer.push_back(farNode);//当相等的时候还还没有装进去的，所以再装一次

        int len = answer.size();
        vector<int> ans;
        if(len%2==1)
            ans.push_back(answer[len/2]);
        else{
            ans.push_back(answer[len/2]);
            ans.push_back(answer[len/2-1]);
        }
        return ans;
    }

private:
    vector<vector<int>> graph;
    vector<int> path;
    vector<int> answer;
    vector<int> visited;
    queue<int> que;

    int getFarNode(int x){//返回离它最远的点
       int root;
       que.push(x);
       while(!que.empty()){
            root = que.front(); que.pop();
            visited[root] = 1;
            for(int child : graph[root]){
                if (!visited[child]) que.push(child);
            }
       }
       return root;
    }

    int buildAnswer(int root){//记录当前节点的前驱节点
        int maxH = 1, maxNode = root;
        visited[root] = 1;
        for(int child : graph[root]){
            if(!visited[child]){
                int tempH = 1 + buildAnswer(child);
                if (tempH > maxH){
                    maxH = tempH;
                    maxNode = child;
                }
            }
        }
        path[root] = maxNode;//构建前驱节点
        return maxH;
    }
};

```

### 解题思路
直接看注释吧，借鉴了大神的解法，不一一贴出名字了。

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);//节点的入度
        vector< vector<int>> dirTable(numCourses,vector<int>());//使用邻接表存储该图形
 //       vector< vector<int>> dirTableGraph(numCourses,vector<int>());

        for(auto v : prerequisites){//处理数据
            indegree[v[0]]++;//计算每个节点的入度
            dirTable[v[1]].push_back(v[0]);//找出每个节点的邻接节点，保存到dirTable中
        }

        //找出入度为0的节点，保存到队列中
        queue<int> que;
        for(int i = 0; i < indegree.size();i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        //使用DFS来进行拓扑排序，如果所有节点都被遍历过，说明该课程表可以被全部完成

        vector<int> result;
        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            result.push_back(tmp);

            for(auto node : dirTable[tmp] ){
                if((--indegree[node]) == 0){
                    que.push(node);
                }
            }
        }
        if(result.size() == numCourses){
            return result;
        }else{
            vector<int> vec;
            return vec;
        }
        
    }
};
```
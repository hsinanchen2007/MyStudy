# 207. 课程表
**方法一：DFS**
```
//DFS
class Solution {
public:
	bool dfs(vector<vector<int>> &AdjacencyList,vector<int> &Visit,int numCourses,int Nodenum){
		if( Visit[Nodenum] == 1 )  return false;
		if( Visit[Nodenum] == 2 )  return true;
		
		Visit[Nodenum] = 1;
		for( int adjNodenum : AdjacencyList[Nodenum] ){
			if( !dfs(AdjacencyList,Visit,numCourses,adjNodenum) )
				return false;
		}
		Visit[Nodenum] = 2;
		
		return true;
	}
	
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	
		//创建邻接链表
		vector<vector<int>> AdjacencyList(numCourses);
		for( vector<int> vector_item : prerequisites ){
			AdjacencyList[vector_item[1]].push_back(vector_item[0]);
		}
		
		//Visit数组
		vector<int> Visit(numCourses,0);
		
		for( int i = 0; i < numCourses; ++i ){
			if( !dfs(AdjacencyList,Visit,numCourses,i) )
				return false;
		}
		return true;
    }
};
```

**方法二：拓扑排序**

```
//拓扑排序
class Solution {
private:
	queue<int> m_queue;
public:
	//入度为0的节点入队函数
	bool enQueue(int numCourses,vector<int> &NodeInDegree,vector<vector<int>> &AdjacencyList){
		bool rst = false;
		for(int i = 0; i < numCourses; ++i){
			if( NodeInDegree[i] == 0 ){
				rst = true;
				m_queue.push(i);
				NodeInDegree[i] = -1;
				
				//入度数组重新计算
				for(int j = 0; j < AdjacencyList[i].size(); ++j ){
					--NodeInDegree[AdjacencyList[i][j]];
				}
			}
		}
		return rst;
	}
	
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		//创建邻接链表
		vector<vector<int>> AdjacencyList(numCourses);
		 //建立节点入度数组
		vector<int> NodeInDegree(numCourses,0);
		
		//遍历参数初始化 邻接链表 入度数组 
		for( vector<int> vector_item : prerequisites ){
			++NodeInDegree[vector_item[0]];
			AdjacencyList[vector_item[1]].push_back(vector_item[0]);
		}
		
		while( 1 ){
			if( !enQueue(numCourses,NodeInDegree,AdjacencyList) )
				break;
		}
		
		if( m_queue.size() == numCourses )  
			return true;
		else 
			return false;
    }
};
```


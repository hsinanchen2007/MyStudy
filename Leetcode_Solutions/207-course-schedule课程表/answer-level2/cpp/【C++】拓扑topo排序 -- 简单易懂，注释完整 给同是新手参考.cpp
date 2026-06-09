### 可能是注释最完整的解答，根据题意能得知给出的课程顺序是有依赖关系的，因此想到是拓扑排序
基本上是简单拓扑排序的最简单代码框架了，时空复杂度不怎么好看，优化以后再搞
参考了@ikaruga 的[解法](https://leetcode-cn.com/problems/course-schedule/solution/207-by-ikaruga/)感谢该作者
![image.png](https://pic.leetcode-cn.com/dd1a8d4abae44aec17c276fc91d5fd4ef000ee60f965000153c40e473f4d1754-image.png)

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {                
        vector<int> inDegree(numCourses, 0); // 遍历边缘列表，计算入度
        
        // 有向无环DAG图的存储，使用邻接表
        vector<vector<int>> dirTable(numCourses, vector<int>() );
        for(auto v:prerequisites) {
            inDegree[v[0]]++;  //dstNode的入度+1
            dirTable[v[1]].push_back(v[0]); // 存储srcNode邻接表
        }

        queue<int> que;
        // 然后找到入度=0的索引作为起始点进行拓扑排序，使用队列queue，先将入度为0的enQueue
        for(int i=0;i<inDegree.size();i++) {
            if(inDegree[i]==0) que.push(i);
        }
        vector<int> res;
        while(!que.empty()) {
            auto tmp = que.front(); que.pop();   // 将入度为0的进行出队，那就是每次出一个呗
            res.push_back(tmp);
            for(auto adjnode:dirTable[tmp]){
                if(--inDegree[adjnode]==0)    // 然后跟他有关的边及目标node的入度-1
                    que.push(adjnode);   // 然后再次将入度=0的node进队，直到队列为空，且入度都为0了
            }
        }
        return res.size() == numCourses;        
    }
    
};
```
### 解题思路
- 利用inDegree存储每个顶点的入度
    + 入度：该顶点有几个前序顶点
- 收集入度为0的顶点先输出
- 遍历入度为0的顶点的邻接表，相应将入度-1，push进0入度数组
- 周而复始
时间复杂度：O(N)。图中的每个顶点都处理了一次。
空间复杂度： O(N)。我们使用了一个中间的队列数据结构来存储所有具有0入度的顶点。在最坏的情况下，没有任何先序顶点，队列会包括所有的顶点。

### 代码

```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
    const  findOrder = (numCourses, prerequisites) =>{
        let inDegree=new Array(numCourses).fill(0),res=[],adj=new Array(numCourses),
        temp=[];
        // initialize adj
        for(let i=0;i<numCourses;i++){
            adj[i]=[];
        }
        for(let i=0;i<prerequisites.length;i++){
            adj[prerequisites[i][1]].push(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]+=1;
        }
        for(let i=0;i<numCourses;i++){
            if(inDegree[i]===0){
                temp.push(i);
            }
        }
        while(temp.length>0){
            let top=temp.shift();
            res.push(top);
            for(let i=0;i<adj[top].length;i++){
                inDegree[adj[top][i]]--;
                if(inDegree[adj[top][i]]===0){
                    temp.push(adj[top][i]);
                }
            }
        }
       return res.length===numCourses?res:[];
    };
```
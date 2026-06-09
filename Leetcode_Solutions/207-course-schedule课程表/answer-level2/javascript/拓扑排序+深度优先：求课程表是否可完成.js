## 解题思路
本题采用了拓扑排序和深度优先两种方式解决

### 深度优先遍历
1. 数据结构：图的存储采用邻接表的形式。
- adjacencyTable {Map}：邻接表 key:开始课程,  value:可达课程
- queue {number[]}： index:课程, value:入度数
- stats {Map}： 课程访问状态 key:课程,  value:访问状态{0,1,-1} = {未，正，已}访问
- result {boolean}：false表示有环。
2. 基本思想：  从图中某个顶点v出发，访问此顶点，然后从v的未被访问的邻接点出发深度优先遍历图，直至图中所有和v有路径相通的顶点都被访问到。这是一个递归的搜索过程
3. 主要代码：
```javascript []
    /**从一个节点(入度为0的点)开始，深度优先访问所有节点。 但是可能一个闭环中所有节点入度为0
     *  不过如果碰到环了就直接回退吧，不需要遍历完了
     * @param {number} node 节点名
     */
function dfs(node) {      
      var nextNodes = adjacencyTable.get(node);
      if (nextNodes.length == 0) {
        stats.set(node, -1) //标记为已经访问   
        return;
      };
      stats.set(node, 1) //标记为正在访问     
      for (let i = 0; i < nextNodes.length; i++) {
        if (result == false) return; //每次访问子节点时判断。有环则立即回退
        if (stats.get(nextNodes[i]) == 0) { //未访问，向下进行
          dfs(nextNodes[i])
        } else if (stats.get(nextNodes[i]) == 1) { //访问到正在访问的节点。发现有环
          result = false;
          break;
        } else if (stats.get(nextNodes[i]) == -1) { //已经访问过的节点，不管
          continue;
        }
      }
      stats.set(node, -1); //最后该节点已经访问完全，设置状态-1
      return;
    }
```

### 拓扑排序
1. 数据结构：图的存储采用邻接表的形式。
- adjacencyMatrix {number[][]}：邻接矩阵 行:课程,  列:课程。adjacencyMatrix[i][j]:i课程上了才上j
- queue {number[]}：  value:入度为0的那些节点。
2. 基本思想：  
- 在有向图中选所有没有前驱的顶点并且加入队列。
- 从队列中选一个顶点，从图中删除该顶点和所有以它为尾的弧。(删除出度)。
- 重复上述两步，直至所有顶点输出。如果有还有顶点没输出，则有环。
3. 主要代码：
```javascript []
// 从队首开始移出元素，然后改变邻接矩阵
  while (queue.length) {
    let current = queue.shift(); //取一个入度为0的节点
    for (let j = 0; j < numCourses; j++) { //遍历这行
      if (adjacencyMatrix[current][j] == 1) {
        adjacencyMatrix[current][j] = 0;
        for (let i = 0; i < numCourses; i++) { //查看删除了当前节点后 的 连接的节点是否出度为0了
            if (adjacencyMatrix[i][j] == 1) {
              break;
            } else {
              if (i == numCourses - 1) {
                  queue.push(j);
              }
            }
        }      
      }        
    }
}
```





### 代码整合

```javascript
/**
   * @param {number} numCourses
   * @param {number[][]} prerequisites
   * @return {boolean}
   */
  var canFinish = function (numCourses, prerequisites) {
      /**
     * ******DFS方法和Topological 深度优先与拓扑排序法******
     *         **     **           
     *        *****************      
     *      **        **             
     *    **          **          
     *      *********************     
     *             ** ** **          
     *            **  **  **            
     *           **   **   **          
     *          **    **    **          
     *         **     **     **    
     * ******DFS方法和Topological 深度优先与拓扑排序法******
     */
    //1.拓扑排序解决
    function Topological(numCourses, prerequisites){
        //创建邻接矩阵
        var adjacencyMatrix = new Array(numCourses);
        var queue = [];
        for (let i = 0; i < numCourses; i++) {
        adjacencyMatrix[i] = new Array(numCourses);
        adjacencyMatrix[i].fill(0);
        };
        for (let i = 0; i < prerequisites.length; i++) {
        adjacencyMatrix[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
        //找到入度为0的点入队列     遍历j:0->n列;
        for (let j = 0; j < numCourses; j++) {
        let count = 0;
        for (let i = 0; i < numCourses; i++)
            if (adjacencyMatrix[i][j] == 1)
            count++;
        if (count == 0)
            queue.push(j);
        }
        //从队首开始移出元素，然后改变邻接矩阵
        while (queue.length) {
        let current = queue.shift();
        for (let j = 0; j < numCourses; j++) {
            if (adjacencyMatrix[current][j] == 1) {
              adjacencyMatrix[current][j] = 0;
              for (let i = 0; i < numCourses; i++) {
                  if (adjacencyMatrix[i][j] == 1) {
                    break;
                  } else {
                    if (i == numCourses - 1) {
                        queue.push(j);
                    }
                  }
              }      
            }        
        }
      }
        //查看矩阵是否全为0;
        for (let i = 0; i < numCourses; i++) {
        for (let j = 0; j < numCourses; j++) {
            if (adjacencyMatrix[i][j] == 1) return false;
        }
        if (i == numCourses - 1) return true;
        }
    }

    //2.深度优先DFS遍历，只要不存在环，就成功
  function DFS(numCourses, prerequisites) {
      /**从一个节点(入度为0的点)开始，深度优先访问所有节点。 但是可能一个闭环中所有节点入度为0
     *  不过如果碰到环了就直接回退吧，不需要遍历完了
     * @param {number} node 节点名
     */
    function dfs(node) {
      var nextNodes = adjacencyTable.get(node);
      if (nextNodes.length == 0) {
        stats.set(node, -1)
        return;
      };
      stats.set(node, 1)            
      for (let i = 0; i < nextNodes.length; i++) {
        if (result == false) return;
        if (stats.get(nextNodes[i]) == 0) {
          dfs(nextNodes[i])
        } else if (stats.get(nextNodes[i]) == 1) {
          result = false;
          break;
        } else if (stats.get(nextNodes[i]) == -1) {
          continue;
        }
      }
      stats.set(node, -1);
      return;
    }
    //创建邻接表
    var adjacencyTable = new Map()
    var queue = new Array(numCourses) //记录节点入度数
    queue.fill(0) //初始化入度为0的点值为0。
    var stats = new Map(); //key:节点,value:访问状态。0未被访问，1正在访问，-1已经被其他访问
    //最后状态全为-1，则表示访问完了。
    var result = true; //记录是否有环。和是否全部访问完。true 为遍历到的节点是无环的
    for (let i = 0; i < numCourses; i++) {
      adjacencyTable.set(i, []);
      stats.set(i, 0);
    }
    for (let i = 0; i < prerequisites.length; i++) {
      adjacencyTable.get(prerequisites[i][1]).push(prerequisites[i][0]);
    }
    // console.log('邻接表：', adjacencyTable)
    //找出入度为0的点
    adjacencyTable.forEach((val, key) => {
      val.forEach((item, index) => {
        queue[item]++
      })
    })
    // console.log('入度数：', queue)
    //从每个入度为0的点开始遍历图
    queue.forEach((item, index) => {
      if (item == 0) {
        dfs(index);
      }
    })
    //查看状态;
    if (result == false) return false;
    // console.log('最终状态：', stats)
    for (let i = 0; i < stats.size; i++) {
      if (stats.get(i) == 0) return false;
    }
    return true;
  }

    //调用
    //调用
    //调用
    //调用
    //1.拓扑排序解决
    // return Topological(numCourses, prerequisites);

    //2.DFS深度优先
    return DFS(numCourses, prerequisites)    
  };  
```
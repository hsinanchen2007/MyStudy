### 解题思路
![TIM图片20200305164545.png](https://pic.leetcode-cn.com/e9e94e515f7cef28f202a8a99cdebdff20cb599c97c898a7245a0d7a577e5a06-TIM%E5%9B%BE%E7%89%8720200305164545.png)
很遗憾，内存占用还是很高，但是在下水平有限想不到特别好的方法优化内存了。

水平有限，大致说一下思路
1.初始化邻接表，初始化入度，记录所有的节点是否被找到
2.从0遍历到numCourses 广度遍历入度为0并且未被找到的节点，将被找到的节点记录，记录被找到的总数，然后‘假装’将该节点删除，也就是将该节点的所有兄弟节点的入度减一
        如果广度遍历过程中存在环路的话，寻址会回到之前遍历过的节点，相反如果不存在环的话广度遍历就不会遇到重复的节点，利用这一点可         以提前结束循环，节省时间。
3.对比节点是否全部找到，因为有环路的话在节点剥离过程中入度始终不会为0，一直不满足条件，所以不会被找到
### 代码

```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {                      
    let indegree = new Array(numCourses).fill(0)       // 顶点的入度
    let dirctMap = []                                  //邻接表(在dfs遍历的时候用得到)
    let result = 0                                     //正规的拓扑排序应该得到一个数组，内容是顺序表，为了节省内存用数量替代
    let ifFind = new Array(numCourses).fill(0)         //用来记录找到了哪些节点
    for(let i = 0;i<numCourses;i++){                   //初始化邻接表
        dirctMap.push([])
    }
    for(let i = 0,l = prerequisites.length;i<l;i++){    //初始化邻接表
        let item = prerequisites[i];
        indegree[item[0]]++                  //记录该节点的入度
        dirctMap[item[1]].push(item[0])      //在邻接表里记录该节点
    }
    for(let i = 0;i<numCourses;i++){         //循环遍历所有节点
            dfs(dirctMap,i,0)
    }
    /*
    *dirctMap : 要遍历的邻接表
    *index : 当前节点
    *status : 是否第一层
    */
    function dfs(dirctMap,index,status){
        if(status&&ifFind[index]===1){  //如果不是第一层并且该节点已经被找到过了，那么说明遇到了环路，则提前结束，返回结果
            return false
        }
        if(ifFind[index] === 0&& indegree[index]===0){//判断入度为0并且违背找到过的节点可以进入
            result++            //找到一个节点，总数量+1
            ifFind[index] = 1;  //标记该节点被找到
            dirctMap[index].forEach(i=>{    //广度遍历该节点的兄弟节点
                indegree[i]--               //由于原来的节点被‘移除了’所以兄弟节点的入度要减一
                dfs(dirctMap,i,1)
            })
        }
    }
    return result === numCourses            //如果最后找到的节点数量小于总数的话就说明有环路 
                                            //(因为有环路的话在剥离过程中入度始终不会为0，一直不满足条件，所以不会被找到)
}
```
### 解题思路
就是简单的拓扑排序，唯一一点不同的就是把边缘列表转换为邻接矩阵，其他的就是正常的拓扑排序做法

### 代码

```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
//转换为邻接矩阵
var canFinish = function(numCourses, prerequisites){
    let sonList = [];
    for(let i = 0; i < numCourses; i++){
        sonList[i] = [];
    }
    let result = [];
    let stack = [];
    let inCount = [];
    //生成邻接矩阵；
    for(let i = 0; i < prerequisites.length; i++){
        let pre = prerequisites[i][1], next = prerequisites[i][0];
        sonList[pre].push(next);
        if(!inCount[next]){
            inCount[next] = 1;
        }else{
            inCount[next]++;
        }
    }
    //找出没有没有前驱的节点；
    for(let i = 0; i < numCourses; i++){
        if(!inCount[i]){
            stack.push(i);
        }
    }
    while(stack.length > 0){
        let node = stack.pop();
        result.push(node);
        sonList[node].forEach(item =>{
            inCount[item]--;
            if(inCount[item] == 0){
                stack.push(item);
            }
        })
    }    
    return result.length == numCourses
};
```
### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
     let order = [];
     let queue = [];
     let map = new Map();
     let indegree = new Array(numCourses).fill(0);

     for(const [e,v] of prerequisites){
         if(map.has(v)){
             map.get(v).push(e);
         }else{
             map.set(v,[e]);
         }
         indegree[e]++;
     }
     for(let i=0;i<indegree.length;i++){
         if(indegree[i]==0) queue.push(i);
     }
     while(queue.length){
         let v = queue.shift();
         if(map.get(v)){
             for(let e of map.get(v)){
                 indegree[e]--;
                 if(indegree[e]==0) queue.push(e);
             }
         }
         order.push(v);
     }
     return order.length==numCourses;
};
```
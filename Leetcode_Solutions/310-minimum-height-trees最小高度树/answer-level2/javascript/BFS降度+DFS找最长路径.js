## BFS 一层一层剥离最终找到想要的答案
```javascript
    /**
     * 改进后寻找图的最小高度树的根节点方法：
     * 借用拓扑排序中度的概念，最小高度树的根节点肯定不会是一个入度为1的节点，即邻接表长度为1
     * 依次删除这些叶子节点的邻接点的邻接表中的它本身，如果邻接表中节点的度也是1，那么就放回中间数组。
     * 可以将上述过程理解为剥洋葱法
     * 最终题解为1个或者两个，即为1个根节点或者2个根节点
     * 总体来讲，这种方法不容易想到
     * @param n
     * @param edges
     * @returns {[]|number[]}
     */
    const findMinHeightTrees1=(n, edges)=>{
        if(edges.length<=0) return [0];
        let adj=new Array(n),leaves=[];
        for(let i=0;i<n;i++){
            adj[i]=[];
        }
        for(let i=0;i<edges.length;i++){
            adj[edges[i][0]].push(edges[i][1]);
            adj[edges[i][1]].push(edges[i][0]);
        }
        // find leaves
        for(let i=0;i<n;i++){
            if (adj[i].length===1){
                leaves.push(i);
            }
        }
        console.info(leaves);
        while(n>2){
            n-=leaves.length;
            let next=[];
            for(let i=0;i<leaves.length;i++){
                // 叶子节点的相邻节点
                temp=adj[leaves[i]].pop();
                // 在temp的邻接表中删除这个叶子节点
                for(let j=0;j<adj[temp].length;j++){
                    if(adj[temp][j]===leaves[i]){
                        adj[temp].splice(j,1);
                        break;
                    }
                }
                if (adj[temp].length===1){
                    next.push(temp);
                }
            }
            leaves=next;
        }
       return leaves;
    };
    // 以这个测试用例为例，遍历步骤是：从0-5-6-3-4-1-2，相当于剥离0-5-6，再次剥离3-4，最终确定next为1，2
    console.info(findMinHeightTrees1(7,[[0,1],[1,2],[1,3],[2,4],[3,5],[4,6]]));
    // 从 1-2-5-0-4-3，相当于剥离1-2-5,最终确定next为3
    console.info(findMinHeightTrees1(6,[[0,1],[0,2],[0,3],[3,4],[4,5]]));
```
## DFS找最长路径，中间位置的一个或者两个顶点即为所求(无奈超时)
```javascript
    /**
     * 通过观察题解可以看出来我们找到一条最长的路径之后截取中间节点即为所求答案
     * 利用dfs查找最长路径
     * @param n
     * @param edges
     */
    const findMinHeightTrees2=(n, edges)=>{
        if(edges.length<=0) return [0];
        let adj=new Array(n),leaves=[],maxLen=0,longestPath=[];
        for(let i=0;i<n;i++){
            adj[i]=[];
        }
        for(let i=0;i<edges.length;i++){
            adj[edges[i][0]].push(edges[i][1]);
            adj[edges[i][1]].push(edges[i][0]);
        }
        for(let i=0;i<n;i++){
            if (adj[i].length===1){
                leaves.push(i);
            }
        }
        // console.info(leaves,adj);
        // 假如我们用回溯法的思路来解决这个找寻最长路径的问题会是什么样子呢？
        const find=(start,adj,map,res)=>{
            res.push(start);
            map.set(start,true);
            if(adj[start].length===1&&map.has(adj[start][0])){
                // console.info(res);
                if(res.length>maxLen){
                    maxLen=res.length;
                    longestPath=JSON.parse(JSON.stringify(res));
                }
            }
            for(let i=0;i<adj[start].length;i++){
                if(!map.has(adj[start][i])){
                    find(adj[start][i],adj,map,res);
                    // 回溯操作
                    res.pop();
                }
            }
        };
        for(let i=0;i<leaves.length;i++){
            find(leaves[i],adj,new Map(),[]);
        }
        // console.info(maxLen,longestPath);
        return maxLen%2===0?[longestPath[longestPath.length/2],longestPath[maxLen/2-1]]:[longestPath[Math.floor(maxLen/2)]];
    };

```
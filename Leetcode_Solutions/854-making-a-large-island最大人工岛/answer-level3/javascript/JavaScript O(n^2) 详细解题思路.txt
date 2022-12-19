注：O(n^2)而不是O(n^3)是因为再遍历gird时，遍历过一次的坐标不会被重复遍历，因此grid[i][j
]的每个点只会被遍历一次，因此是O(n^2)。  
解题思路：  
1. 求取某个岛屿的面积，保存这个岛屿的所有点的对应索引  
  这个好求了，直接`dfs`或`wfs`，保存对应下标即可
2. 根据上一个步骤的结果对岛屿进行编号，初始置为`-1`依次为`-1`,`-2`,`-3`...
3. 将岛屿的编号与其对应的大小一一记录下来
4. 对岛屿中所有点填充为其对应下标   
经过上面步骤，求某个点对应的岛屿的面积就简单了：   
    * 直接先通过这个点对应的值拿到岛屿的编号（因为我们在第4步将岛屿编号记录到了岛屿的点上）  
    * 然后通过通过记录的岛屿编号直接就能拿到岛屿了大小了。    
时间复杂度为O(1)
5. 查找`grid`中为`0`的点（海洋），将其填充为岛屿时的岛屿大小为它的大小加上它上下左右岛屿（若存在）的大小
6. 第5步所有结果取最大值，若没有海洋，那么直接返回grid的大小即可。

```javascript
//思路：
//对于每个海洋，遍历所有的与其相邻的陆地。取最大值

var largestIsland = function(grid) {

    let ARR = [[0,1],[1,0],[0,-1],[-1,0]];
    
    let pieceIndex=-1;//给岛屿编号使用,初始编号为-1，依次递减，用负数以利用grid的空间，避免开劈新空间，若为整数可能与1造成混用。
    //储存对应的编号的岛屿的面积
    let pieceInfoHash=new Map();
    let zeroIndexArr=[];//用zeroIndexArr记录所有为0的坐标避免重复使用
    let result=0;
    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[0].length;j++){
             if(grid[i][j]===1){
                 let stack=[[i,j]];
                 grid[i][j]*=-1;//标记为已访问
                 let visited=new Array();
                 let size=1;
                 while(stack.length>0){
                     let [pi,pj]=stack.pop();
                     visited.push([pi,pj]);
                     for(let [di,dj] of ARR){
                         let [ni,nj]=[pi+di,pj+dj];
                         if(inRange(ni,nj) && grid[ni][nj]===1){
                             grid[ni][nj]*=-1;//标记为已访问
                             size++;
                             stack.push([ni,nj]);   
                         }
                     }
                 }
                 result = Math.max(size,result);//单个岛屿的最大面积
                 pieceInfoHash.set(pieceIndex,size);
                 for(let [ni,nj] of visited){
                     grid[ni][nj]=pieceIndex
                 }
                 pieceIndex--;
             }else if(grid[i][j]===0){
                 zeroIndexArr.push([i,j])
             }
        }
    }
    // console.log(grid)
    // console.log("单个岛屿的最大值为：",result);
    
    for(let [i,j] of zeroIndexArr){
        let size=1;
        let visitedLand=new Set();
        // console.log(i,j,":====")
        for(let [di,dj] of ARR){
            let [ni,nj]=[i+di,j+dj];
            if(inRange(ni,nj)){
                let landNo=grid[ni][nj]
                if(landNo<0 && !visitedLand.has(landNo)){
                    visitedLand.add(landNo);
                    // console.log(size,"编号：",landNo,pieceInfoHash.get(landNo))
                    size+=pieceInfoHash.get(landNo);
                }
            }
        }
        result=Math.max(size,result);
    }
    return result;
    
    function inRange(ni,nj){
        return ni>=0 && ni<grid.length &&  nj>=0 &&  nj<grid[0].length;
    }
    
};
```
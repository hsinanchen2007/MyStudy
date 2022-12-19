判断某个点：`P2(x,y)`是否在点：`P1(i,j)`的照耀范围,只需要判断向量：`(P1,P2)`是否与`x`或`y`轴平行，或者与直线`y=x`平行，向量：`(P1,P2)=(x-i,y-j)`因此只需要判断：`x-i===0`或`y-j===0`或`|x-i|===|y-j|`  
因此判断某个点`(x,y)`是否被照亮只需要判断所有的`lamps`是否能照亮`(x,y)`，时间复杂度为`O(lamps.length)`。
因为有`queries.length`次查询，因此时间复杂度为：`O(queries.length * lamps.length)`  
时间复杂度： `O(N*N)` `M`为`queries`的长度,`N`为`lamps`的长度  
空间复杂度： `O(N)+O(M)` `N`为`queries`的长度,`M`为`lamps`的长度，因有借助一个临时的`lamps`来熄灭`(x,y)`8个点范围内的等
```javascript
var gridIllumination = function(N, lamps, queries) {
    let ans = new Array(N)
    let i=0;
    let inRange=(x,y)=>x>=0 && y>=0 &&x<N && y<N;
    for(let [x,y] of queries){
        ans[i] = isLight(x,y);
        lamps=ans[i]?lamps.filter(([i,j])=>i>x+1||i<x-1||j>y+1||j<y-1):lamps;
        i++;
    }
    return ans;
    function isLight(x,y){
        for(let [i,j] of lamps){
            let [p1,p2]=[x-i,y-j];
            if(p1===0 || p2===0 || Math.abs(p1)===Math.abs(p2))return 1;
        }
        return 0;
    }
};
```
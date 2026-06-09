矩阵是每个第二维长度都相等的二维数组，因此无需再次定义第二层每个数组的长度，这样将原本时间复杂度为O(n^2)的计算直接降为O(1)
![9373b96751015e8e9eb81dd66a1b7dc99e2b2476eb3bdeb73d8bcf74f9791af7-leecode.png](https://pic.leetcode-cn.com/894082985485ae9a256064243f15c3061a3bf9b0bd3e2c465aa5f8d5924efb64-9373b96751015e8e9eb81dd66a1b7dc99e2b2476eb3bdeb73d8bcf74f9791af7-leecode.png)

**代码如下**
```
var countNegatives = function(grid) {
    let arr = [],m = grid.length
    for(let i=0;i<m;i++){
        let n = grid[0].length
        for(let j=0;j<n;j++){
            if(grid[i][j]<0){
                arr.push(grid[i][j])
            }
        }
    }
    let len = arr.length
    return len
};
```


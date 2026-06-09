### 解题思路
理解题意理解了很久。。后来看图才看懂了，于是就想到了先加再减的算法。
先假设所有柱体之间都有空隙不挨着，算出单个柱体本身的总面积，就是 （m*4-2）了，然后全部相加。
接着从左往右，从上往下开始减重合的地方（和我们阅读的顺序一样），
发现在除了第一列(不用算左面))和最后一排（不用算下面）的柱体，其他的柱体都只需要减去自身左边和下方的柱体重合面积就可以，
这样的话，除了第一列和最后一排，每个柱体跟自身左边和下方柱体作对比，高度小的一方即为重合的面积，柱体本身总面积减去左边和下边重合的面积，最后所有柱体减一遍就可以了。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    const len = grid.length
    let num = 0
    for(let i = 0; i < len; i++){
        for(let j = 0; j < grid[i].length; j++){
            let index = grid[i][j]
// 计算柱体本身不遮挡的总面积
            if(grid[i][j] > 0){
                num += index * 4 + 2
            }
// 除去第一列，不用算左边
            if(j > 0){
                let left = Math.min(index,grid[i][j - 1])
                num -= left * 2
            }
// 除去最后一行，不用算下边
            if(i < len - 1){
                let bottom = Math.min(index,grid[i + 1][j])
                num -= bottom * 2
            }
        }
    }
    return num
};
```
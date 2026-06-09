### 解题思路
1. 创建一个 n x n 的二维数组 arr；
2. 创建一个 初始值为 1 的累加变量 k；
3. 数组 arr 的长度（行数）为 n，所以创建一个从 0 开始，循环次数为 n 的外层循环；
4. 按照当前螺旋循环的最外层的上边、右边、下边、左边的顺序把 k 的值赋值给数组 arr 的对应位置，并且每赋值一次，k 的值累加 1；
5. 最后返回得到的数组

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[][]}
 */
let generateMatrix = n => {
    //创建 n x n 的二维数组
    let arr = new Array(n);
    for(let i = 0; i < n; i++){
        arr[i] = new Array(n);
    }

    let k = 1;
    for(let i = 0; i < n; i++){
        //上行 索引的列变 行不变，且 列的变化顺序为从左到右，列号 j 自增，取值顺序为 i ～ n-1-i
        for(let j = i; j < n - i; j++){
            arr[i][j] = k++;
        }
        //右列 索引的行变 列不变 且 行的变化顺序为从上到下，行号 j 自增，取值顺序为 i+1 ～ n-1-i
        for(let j = i + 1; j < n - i; j++){
            arr[j][n-1-i] = k++;
        }
        //下行 索引的列变 行不变 且 列的变化顺序为从右到左，列号 j 自减，取值顺序为 n-2-i ～ i 
        for(let j = n - 2 - i; j >= i; j--){
            arr[n-1-i][j] = k++;
        }
        //左列 索引的行变 列不变 且 行的变化顺序为从下到上，行号 j 自减，取值顺序为 n-2-i ～ i+1
        for(let j = n - 2 - i; j > i; j--){
            arr[j][i] = k++;
        }
    }
    //返回最终结果
    return arr;
};
```
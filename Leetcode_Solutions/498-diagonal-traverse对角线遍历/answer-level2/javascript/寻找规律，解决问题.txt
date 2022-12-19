### 解题思路

寻找规律，如下图所示
![image.png](https://pic.leetcode-cn.com/95cd2e0a314c12bf809e5ee47b8228dfcbb3b524375b66d3cc8f07c13655b1d1-image.png)


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var arrOperation = (arr1, arr2, operation = (item1, item2) => item1 + item2) => {
    if (!Array.isArray(arr1) && !Array.isArray(arr2))
        return operation(arr1, arr2);
    if (arr1 instanceof Array &&
        arr2 instanceof Array &&
        arr1.length === arr2.length) {
        const ans = new Array(arr1.length);
        for (let i = 0; i < arr1.length; i++)
            ans[i] = arrOperation(arr1[i], arr2[i], operation);
        return ans;
    }
    else
        throw new Error('两个数组的类型不一致');
};
isOneColumn = (o) => o.every(item => item instanceof Array && item.length === 1);
var findDiagonalOrder = function(matrix) {
    if (matrix.length === 0) return []
    if (matrix.length === 1)
        return matrix[0];
    if (isOneColumn(matrix)) return matrix.map(item => item[0])
    const helper = {
        right: [0, 1],
        down: [1, 0],
        right_up: [-1, 1],
        left_down: [1, -1]
    };
    let [i, j, index] = [0, 0, 0];
    let [row, column] = [matrix.length, matrix[0].length];
    const ans = new Array(row * column);
    while (index < row * column) {
        const isEven = (i + j) % 2 === 0;
        let tmp = [-1, -1];
        ans[index++] = matrix[i][j];
        if (i === 0 && j < column - 1)
            tmp = isEven ? helper.right : helper.left_down;
        else if (i === 0 && j === column - 1)
            tmp = isEven ? helper.down : helper.left_down;
        else if (i < row - 1 && j === 0)
            tmp = isEven ? helper.right_up : helper.down;
        else if (i < row - 1 && j === column - 1)
            tmp = isEven ? helper.down : helper.left_down;
        else if (i === row - 1 && j === 0)
            tmp = isEven ? helper.right_up : helper.right;
        else if (i === row - 1 && j < column - 1)
            tmp = isEven ? helper.right_up : helper.right;
        else
            tmp = isEven ? helper.right_up : helper.left_down;
        [i, j] = arrOperation([i, j], tmp);
    }
    return ans;
};
```

### typescript 代码

```typescript
const arrOperation = <T>(
  arr1: any[] | T,
  arr2: any[] | T,
  operation = (item1: any, item2: any) => item1 + item2
): any[] | T => {
  if (!Array.isArray(arr1) && !Array.isArray(arr2)) return operation(arr1, arr2)

  if (
    arr1 instanceof Array &&
    arr2 instanceof Array &&
    (arr1 as any[]).length === (arr2 as any[]).length
  ) {
    const ans = new Array(arr1.length)
    for (let i = 0; i < arr1.length; i++)
      ans[i] = arrOperation(arr1[i], arr2[i], operation)
    return ans
  } else throw new Error('两个数组的类型不一致')
}
const isOneColumn = (o: any[]) =>
  o.every(item => item instanceof Array && item.length === 1)

const findDiagonalOrder = function(matrix: number[][]): number[] {
  if (matrix.length === 0) return []
  if (isOneColumn(matrix)) return matrix.map(item => item[0])
  if (matrix.length === 1) return matrix[0]
  const helper: { [index: string]: [number, number] } = {
    right: [0, 1],
    down: [1, 0],
    right_up: [-1, 1],
    left_down: [1, -1]
  }
  let [i, j, index] = [0, 0, 0]
  let [row, column] = [matrix.length, matrix[0].length]
  const ans: number[] = new Array(row * column)
  while (index < row * column) {
    const isEven = (i + j) % 2 === 0
    let tmp: [number, number] = [-1, -1]
    ans[index++] = matrix[i][j]
    if (i === 0 && j < column - 1)
      tmp = isEven ? helper.right : helper.left_down
    else if (i === 0 && j === column - 1)
      tmp = isEven ? helper.down : helper.left_down
    else if (i < row - 1 && j === 0)
      tmp = isEven ? helper.right_up : helper.down
    else if (i < row - 1 && j === column - 1)
      tmp = isEven ? helper.down : helper.left_down
    else if (i === row - 1 && j === 0)
      tmp = isEven ? helper.right_up : helper.right
    else if (i === row - 1 && j < column - 1)
      tmp = isEven ? helper.right_up : helper.right
    else tmp = isEven ? helper.right_up : helper.left_down
    ;[i, j] = arrOperation([i, j], tmp)
  }
  return ans
}

```
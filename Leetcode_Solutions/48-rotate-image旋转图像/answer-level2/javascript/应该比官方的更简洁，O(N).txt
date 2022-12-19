先放代码  
```js
const temp = matrix.flat();
  const temp = matrix.reduce((acc, val) => acc.concat(val), []);
  const length = matrix[0].length;
  matrix.forEach((item, i) => {
    item.forEach((ele, j) => {
      item[j] = temp[length * (length - 1 - j) + i];
    });
  });
```  

如代码所示，先把二维数组扁平化为一维数组，例如，给定的
```js
matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
```
转为：
`temp = [1, 2, 3, 4, 5, 6, 7, 8, 9]`

其实，预期的数组结构和转换后的temp数组有一个数学关系，每一项的值为  
`temp[length * (length - 1 - j) + i]`  

其中，`length`为第二层数组的长度，在这里为3，`i`为第一层循环的索引，`j`为第二层数组循环的索引  

时间复杂度：$O(N)$  
空间复杂度：$O(1)$ 

Github求star！[github美女地址](https://github.com/zytjs/js-algorithm)
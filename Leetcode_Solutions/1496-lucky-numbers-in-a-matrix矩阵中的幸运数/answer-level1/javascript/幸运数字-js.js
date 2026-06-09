### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */

//1.外层for 循环  找出每一行最小位置的索引
//2.内层for 循环  找出当前行最小索引的每一列的值，放入一个新数组并排序判断是否为最大值 符合条件 return
//3.for循环结束，则证明没有存在幸运数，直接return 空数组
var luckyNumbers = function (matrix) {
    for (var i = 0; i < matrix.length; i++) { // 循环找出每一行的最小索引位置
        var arr = [...matrix[i]].sort(function (a, b) { return a - b }) // 对每一行进行正向排序
        var index = matrix[i].indexOf(arr[0]); // 取得原行的最小值的位置
        var arr1 = [];// 存储最最小值对应的列的值
        for (var j = 0; j < matrix.length; j++) {
            arr1.push(matrix[j][index]); //找出对应列的值，存进数组中
        }
        arr1.sort(function (a, b) { return b - a }) // 对对应列的值进行倒序
        if (arr1[0] == arr[0]) { //判断行跟列的最大最小值是否相等
            return [arr1[0]]; // 相等则证明是幸运数，直接return 结束
        }
    }
    return []; //循环结束,循环过程中没有找到幸运数 ，直接return 空数组[]
};
```
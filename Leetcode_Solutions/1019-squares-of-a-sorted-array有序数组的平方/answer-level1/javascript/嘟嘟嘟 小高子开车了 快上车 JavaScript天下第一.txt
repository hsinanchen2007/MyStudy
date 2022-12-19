```javascript []
/**
 * @param {number[]} A
 * @return {number[]}
 */
// 1.将数组按绝对值递增排序 
// arrayObject.sort(sortby)
// 如果调用该方法时没有使用参数，将按字母顺序对数组中的元素进行排序，说得更精确点，是按照字符编码的顺序进行排序。要实现这一点，首先应把数组的元素都转换成字符串（如有必要），以便进行比较。

// 如果想按照其他标准进行排序，就需要提供比较函数，该函数要比较两个值，然后返回一个用于说明这两个值的相对顺序的数字。比较函数应该具有两个参数 a 和 b，其返回值如下：

// 若 a 小于 b，在排序后的数组中 a 应该出现在 b 之前，则返回一个小于 0 的值。
// 若 a 等于 b，则返回 0。
// 若 a 大于 b，则返回一个大于 0 的值。

// abs() 方法可返回数的绝对值。

// 2.遍历数组 将原始数组值进行平方 
// ！！！for in 不适合遍历数组

// arr.forEach(callback[, thisArg]);
// 参数节
// callback
// 为数组中每个元素执行的函数，该函数接收三个参数：
//  currentValue
//  数组中正在处理的当前元素。
//  index可选
//  数组中正在处理的当前元素的索引。
//  array可选
//  forEach() 方法正在操作的数组。
// thisArg可选
// 可选参数。当执行回调函数时用作 this 的值(参考对象)。
// 返回值节
// undefined.

// pow() 方法可返回 x 的 y 次幂的值。

var sortedSquares = function(A) {
    function sortNumber(a,b){
        return Math.abs(a) - Math.abs(b)
    }
    A.sort(sortNumber)
    A.forEach((val,index)=>{
        A[index] = Math.pow(A[index],2)
    })
    return A
};
```


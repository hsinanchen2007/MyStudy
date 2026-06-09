### 解题思路
js获取数组最大值最小值max,min

数组排序，获取第一个和最后一个为最小值最大值;此方法通用
Math自带函数Math.min(),Math.max();数组长度过大会报错。Maximum call stack size exceeded
遍历数组，定义变量a等于第一个值，遍历数组与每个元素比较，每次最大的赋值给a；遍历完成则a为最大值。最小值同理；


### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
    return Math.min(...numbers)
};
```
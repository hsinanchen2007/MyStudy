第一种方法代码通过减少循环次数并且缩减循环内进行运算的方法实现高效查找
```
var minArray = function(numbers) {
    let i = null;
    for(i=0;numbers[i] <= numbers[i+1] && i<numbers.length;++i);
    if (numbers[i+1] !== undefined) {
        return numbers[i+1]
    }
    return numbers[0]
};
```

第二种方法极其简单，极少的代码完成运算
```
<!-- 合理利用es6的数组解构赋值 -->
var minArray = function(numbers) {
    return Math.min(...numbers)
}
```

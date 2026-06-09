题特别简单，什么hash，相邻元素这些普通的或者找规律的就不提了

#### 原地解法
其实很多hard的原地求解都用到了这种思想，有几个特点
+ 每个元素都 >= 0 (若等于0，需要做特殊处理)
+ 寻找的目的数有规律，比如这里只需要找到第一个重复的数即可
+ 数组元素 <= 数组长度 (这里就不满足，严格来说这并不是原地解)

于是我们用 负数来替代目的元素，只需要找到目的元素是负数的数即可

```
var repeatedNTimes = function(A) {
    for(let value of A.values()) {
        value = Math.abs(value)
        if(A[value] < 0 || Object.is(A[value],-0)) return value
        A[value] = A[value] !== undefined ? - A[value] : -1   
    }
};
```
当然，也可以利用语言特点对0做特殊的处理，比如js里 Object.is(0,-0) === false

这里并非绝对纯粹的原地解法，因为不满足第三个特点，不过还是很有趣
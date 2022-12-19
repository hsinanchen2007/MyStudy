### 思路

> 一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，也就是 `time[i] * satisfaction[i]` 

1. 根据这句话，我们可以分析出，要想尽可能将结果最大化，**我们应该尽可能的将`satisfaction`值越大的菜尽量往后放**。所以在判断`satisfaction[]`不全为负以后，将入参数组从小到大排序。

2. 排序后计算`sum(satisfaction[index] * (index + 1))`（当前所有菜品 满意值*时间 的总和）

3. 记录当前最大值为`prevMax`，然后去掉`satisfaction[]`的第一个元素（即满意值最小的菜品）后再进行计算...

4. ...算算算，直到满意度总和最大值不再增长，跳出循环返回结果

> 通过打印每轮循环求和结果，我们可得知满意度总值总是**先增后减**的。所以我们计算到总和不再增长就可提前停止，节约时间，此时得到的局部最大值也就是我们的结果。

---

### 代码

```JavaScript
/**
 * @param {number[]} satisfaction
 * @return {number}
 */

var maxSatisfaction = function(satisfaction) {

    if (satisfaction.every(x => x < 0)) {
        return 0;
    }

    const s = satisfaction.sort((x,y) => (x-y));

    let sum = 0;
    let prevMax = -Infinity;

    while (s.length > 0) {
        arr = s.map((val, index) => val * (index + 1));
        sum = arr.reduce((prev, next) => (prev + next));
        if (sum > prevMax) {
            prevMax = sum;
        } else {
            break;
        }
        s.shift();
    }

    return prevMax;

};
```

---

### 优化

#### 初次提交

![image.png](https://pic.leetcode-cn.com/fda85de44c84b74ac81a7fcd54aaee299a623c0f654d613b6a1c8df9e948171d-image.png)

> ~~得亏题目要求不高啊~~

#### Round 1（数组求和优化）

这是竞赛时 ~~（虽然超时了5min）~~ 的提交。之前使用了`sum = eval(arr.join("+"))`的方法~~投机取巧地~~做了数组求和，结果换来了性能在时间和空间上的双重打击。在后续的版本中使用了ES6的`reduce()`方法，大大提高了性能。优化后变成了如下所示：

![image.png](https://pic.leetcode-cn.com/4e3ae3df80f65b2727afd30298cba42d2aec07454c987d526c994f0178f5ede9-image.png)


#### Round 2（冗余循环优化）
之前的版本中，我会循环计算所有的求和结果直到`satisfaction[]`为空。但其实通过 观察 or 打印结果 我们可以发现，满意度总值总是**先增后减**的：
```JavaScript
maxSatisfaction([-1,-8,0,5,-9]);
//console.log(sum)
// -3 10 14 10 5
//       ↑
```

所以计算到**满意度总值不再增长**（`sum <= prevMax`）即可停止计算并返回结果。优化后变成了如下所示：

![image.png](https://pic.leetcode-cn.com/91109f84bcd6452a4fc65e7da74327aff722f5445687bde705d4dc385a0b3192-image.png)


---
### 性能分析

经过几次优化后，执行用时达到了60ms，内存消耗35M上下，性能还可以。
这里的双百没什么意义，因为现在JS的提交还太少了 ~~（我之前420ms+的都能跑时间100% →_→）~~

![image.png](https://pic.leetcode-cn.com/b1de5053176070e6f8e8da78b8093471f891011ca1654e2c0ed5a13b06ba7fd7-image.png)

---

### *关于JS循环哪家强的题外话*

由于`eval()`函数性能不佳，为解决此问题，查找了一番资料发现了这篇文章：[js 数组求和，多种方法，并比较性能](https://www.cnblogs.com/faithZZZ/p/7063952.html)。不过作者模拟的数据量不够大，而且只比较了一次，我在浏览器里测了几次发现有些方法结果会上下浮动，而且拉不开差距。我个人又加大数据量且加入了`for...in` `for...of`比较了几次，得出如下结论：


1. 第一梯队 ~~（朴实无华且很快）~~
`while` `do...while` `for(i=0;i<len;i++)` `reduce()`

2. 第二梯队（二三梯队差距不大）
 `forEach()` `for...of`

3. 第三梯队（主要是各种ES6新方法）
`filter()` `some()` `reduceRight()` < `map()` `every()`

4. 慢的要死梯队（远远慢于前三梯队，不要用）
`eval()` < `for...in`

> 注：
> - 目前测试只针对求和，且不同平台执行可能存在误差
> - 时间短 < 时间长，没写符号的用时差不多，不分先后

希望能对前端工程师们或者其他JS使用者们在处理大量数据时有所帮助。
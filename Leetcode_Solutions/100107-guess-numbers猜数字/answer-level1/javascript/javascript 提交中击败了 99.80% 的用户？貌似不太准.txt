### 解题思路
其实只是一个简单的遍历判断
先声明两个空数组，以备将来传入
声明函数
定义一个数字count = 0，用作记录
for循环，每次循环执行一次判断，满足条件就加1
最后返回结果
调用一次

初次答题，看到结果挺好，优化了一下，没想到还变慢了，随机又跑了几次结果，每次时间都不一样，最快的还是第一次，不过内存消耗都相同，看来这个执行用时并不是特别准。

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
let answer=[],guess=[];
var game = function(arr1, arr2) {
    let count = 0;
    for (let i = 0; i < 3; i++) {
        if (arr1[i] === arr2[i]) {
            count ++
        }
    }
    return count;
};
game(guess,answer)
```
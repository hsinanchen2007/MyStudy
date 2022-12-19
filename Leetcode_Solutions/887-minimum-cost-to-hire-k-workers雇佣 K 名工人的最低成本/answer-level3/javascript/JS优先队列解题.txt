### 解题思路
最初写了个冒泡排序算法，对wage/quality数组排序并同步quality数组，保证每个下标的对应，用时老是超；
观摩了大佬的思路后，敲出了如下的代码
//JS怎么用根堆更优解题？？？
### 代码

```javascript
/**
 * @param {number[]} quality
 * @param {number[]} wage
 * @param {number} K
 * @return {number}
 */
var mincostToHireWorkers = function (quality, wage, K) {
  let workers = [];
  for (let i = 0; i < quality.length; i++) {
    workers[i] = [wage[i] / quality[i], quality[i]]
  }
  let minMoney = Infinity;
  let total = 0;
  let singleDog = [];
  workers.sort(function (a, b) { return a[0] - b[0] });
  for (let i = 0; i < quality.length; i++) {
    total += workers[i][1];
    singleDog.push(workers[i]);
    if (singleDog.length === K) {
      let txt = 0;
      singleDog.forEach(function (value) { txt = Math.max(txt, value[0]) })//用forEach在quality中取最大值，就不用排序了
      minMoney = Math.min(minMoney, txt * total);
      // singleDog.sort(function (a, b) { return a[1] - b[1] });//用排序来寻找最大值效率低
      total -= singleDog.splice(myArray(singleDog), 1)[0][1];//这样写其实容易造成下一轮加进来的工人工作质量比这一轮移除的工人工作质量的要高的情况，不过也没报错
      //尝试用forEach做，还是比for慢一些
      // txt = 0;
      // let maxV = -Infinity;
      // singleDog.forEach(function (value, index) {
      //   if (value[1] > maxV) {
      //     txt = index; maxV = value[1]
      //     return txt
      //   }
      // })
      // total -= singleDog.splice(txt, 1)[0][1];
    }
  } return minMoney;
}
let myArray = function (singleDog) {
  let max = -Infinity;
  for (let j = 0; j < singleDog.length; j++) {
    if (singleDog[j][1] > max) {
      max = singleDog[j][1];
      var len = j;
    }
  } return len
}
```
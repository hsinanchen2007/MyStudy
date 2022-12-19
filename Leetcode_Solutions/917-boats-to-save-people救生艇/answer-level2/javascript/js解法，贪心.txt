[github地址](https://github.com/feikerwu/algorithm-camp/issues/6)


### 题解
大的思路就是贪心，要使总的载人次数最大，那么需要每次载人最多，也就是2个。
如何最重的和最轻的人可以同乘一辆船，则将两人安排到同一辆船。

### 代码
```js
/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function(people, limit) {
  people = people.sort((a, b) => a - b)
  let res = 0;
  while(people.length) {
    let heaviest = people.pop()
    if (people.length > 0 && heaviest + people[0] <= limit) {
      people.shift()
    }
    res++
  }
  return res
};
```
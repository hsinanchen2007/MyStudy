### 解题思路
使用数组进行模拟，将n个数字放入数组，假设当前所处的位置为index,则下一次要删除的位置为index + m,删除该位置元素后，整个数组的长度减1，可以使用取模的方法不断获取index的位置。知道数组中只剩1个元素时返回即可
### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */

var lastRemaining = function(n, m) {
    let arr = []
   for (let i=0; i<n; i++) {
       arr.push(i)
   }
   let id = 0
   while(n > 1){
       index = (index + m - 1) % n
       arr.splice(index,1)
       n-- 
   }
   return arr[0]
};
```
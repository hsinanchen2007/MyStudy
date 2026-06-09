### 解题思路
1.使用bigInt
2.看清题目，题目讲的意思是大于1000000007的数就将他减去1000000007

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
// 
var fib = function(n) {
    if(n === 0) return 0;
    let arr = [1n,1n];
    for(let i =2; i<n ;i++){
      arr[i] = arr[i-1]+arr[i-2];
      // 判断是否大于1000000007
      if (arr[i] > 1000000007n) arr[i] -= 1000000007n;
    }
    return arr[n-1]
};
```
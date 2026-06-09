### 解题思路
最初用遍历做，2600ms，鸡肋，算了，也贴上来吧
### 代码
```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var maxRotateFunction = function (A) {
  if (A.length === 1 || A.length === 0 ) {
    return 0;
  } else {
    let maxR = -Infinity;
    for (let i = 0; i < A.length; i++) {
      let n = 1;
      let copyA = A.slice(1);
      let temp = copyA.reduce(function (total, cur) {
        n += 1;
        return total + n * cur;
      })
      maxR = temp > maxR ? temp : maxR;
      let a = A.pop();
      A.unshift(a);
    }
    return maxR
  }
};
```
### 
然后看了大佬的解题思路，F(j+1)-F(j)=sum(A)-nA[n-1]
### 
```javascript
var maxRotateFunction = function (A) {
  let sum=0; temp=0;
  for (let i = 0; i < A.length; i++) {
    temp += i * A[i];
    sum += A[i];
  }
  let maxR = temp;
  for (let i = A.length - 1; i > 0; i--) {
    temp = sum - A.length * A[i] + temp;
    maxR = temp > maxR ? temp : maxR;
  }
  return maxR
}
```
```javascript
//用reduce 内存消耗稍高
var maxRotateFunction = function (A) {
  if (A.length === 1 || A.length === 0) {
    return 0;
  } else {
  let sum = A.reduce(function (total, cur) {return total + cur});
  let n = 1;
  let temp = A.slice(1).reduce(function (total, cur) {
    n += 1;
    return total + cur * n
  });
  let maxR = temp;
  for (let i = A.length - 1; i > 0; i--) {
    temp = sum - A.length * A[i] + temp;
    maxR = temp > maxR ? temp : maxR;
  }
  return maxR
  }
}
```
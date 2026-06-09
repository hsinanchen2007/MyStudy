### 解题思路
方法一: 直接遍历对比
方法二: 满足长度条件情况下,A+A包含了所有旋转的情况

### 代码

```javascript
/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var rotateString = function(A, B) {
  // 方法一:
  // if(A===B) return true
  // let count = 0
  // while(count<=A.length-1){
  //   A = A.slice(1) + A.slice(0, 1)
  //   if(A===B) return true
  //   count ++
  // }
  // return false

  // 方法二:
  return A.length<=B.length && (A+A).includes(B)
};
```
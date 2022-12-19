### 解题思路

题目就懵逼半分钟, 这都什么鬼描述.  我就看懂了 f(x,y) == z 

好像其他的一大堆没什么多大用处

**反正就是 它给定个函数, 你传两个数进去 它会返回计算过的数**...(都不用管它怎么计算的,这个函数就是CustomFunction中的f函数)

他要的就是customfunction.f(x,y) === z

**1 到 z 共有多少种组合, 我就直接暴力双循环了**

比如 z = 5;  那它共有 

[1,1] [1,2] [1,3] [1,4] [1,5]
[2,1] [2,2] [2,3] [2,4] [2,5]
[3,1] [3,2] [3,3] [3,4] [3,5]
[4,1] [4,2] [4,3] [4,4] [4,5]
[5,1] [5,2] [5,3] [5,4] [5,5]

我们要的就是 f(x,y) === z, 就从上面一堆中判断符合这个条件的就行了

### 代码

```javascript
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 *
 * };
 */
/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */
var findSolution = function(customfunction, z) {
  let list = []
    for(let i=1; i <= z; i++){
      for(let j = 1 ;j <= z; j++){
        if(customfunction.f(i,j)===z){
          list.push([i,j])
        }
      }
    }
    return list
};
```
### 解题思路
算法思考过程：台阶每一次可以爬 1 或者爬 2 个台阶，所以：
1. 当只有一个台阶或者没有台阶时，只有台阶数等同的方法
2. 当有2个台阶时，可以「第一步走一个台阶」或者「第一步走两个台阶」
所以由这一点思考得出，总共的方法= 走一步的方法+走两步的方法
3. 依据第二点“总共的方法= 走一步的方法+走两步的方法”，尝试思考验证三个台阶的情况：
  1. 走两步台阶，后就只剩一个台阶的走法
  2. 走一个台阶，后就只能两个台阶的走法
所以可以很肯定 f(n)=f(n-1)+f(n-2)

由于算法给予递归，会出现栈溢出的情况。所以用cache的方式，把计算过的值记忆下来。同样的计算就可以避免再次递归。


### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  cb = climb();
  return cb(n);
};

function climb(){
  let cache = {};
  return function cb(n){
    if (n in cache) {
      return cache[n]
    } else {
      if(n <= 2) {return n}
      cache[n] = cb(n-1)+cb(n-2)
      return cache[n]
    }
  }
}


```
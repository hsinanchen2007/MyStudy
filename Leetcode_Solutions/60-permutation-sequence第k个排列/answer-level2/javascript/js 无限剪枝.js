![image.png](https://pic.leetcode-cn.com/541535bea906306480183c3be8c984232fafe58d6cc35a8d524d3da32bfb6663-image.png)

思路：
    1.根据 n 的值，遍历出一个 从 1 到 n 的数组，我们采用根据 k 所在的阶乘区间从数组里面取数的方法
    2.先计算出 n-1 的阶乘，假设 n = 5，此时取出一个数，那么不管取出的数是 1、2、3、4、5 中的哪一个，这个数的分支都有 n - 1 （也就是4）的阶乘种方法，我们的循环就是以这种形式继续下去的，直到我们拿到的结果的长度 = n
    3.我们使用字符串来作为 result 的初始化值
    4.这里说明下循环里面的逻辑：
        ①.先计算 k 除以 当前阶乘值 的商和余数
        ②.如果余数等于0，那么在当前条件下还有两种情况：
            一.如果商也等于0，那么，取当前数组的最后一个值
            二.否则取商的上一个位置上的值
          如果余数不等于0，那么直接取这个商位置的值
        ③.取完一个数之后，要把这个数在数组中删除掉的
        ④.阶乘直接除以当前数组的长度 => 转变为低一级的阶乘

```
var getPermutation = function(n, k) {
  let every = 1,
      result = '',
      numsAry = [];
  
  for ( let i = n - 1; i >= 1; i-- ) {
    every = every * i;
  }
  
  for ( let t = 1; t <= n; t++ ) {
    numsAry.push( t );
  }
  
  while ( result.length < n ) {
    let remaind = k % every,
        quotient = Math.floor(k / every);
    k = remaind;
    if ( remaind === 0 ) {
      let pos = quotient === 0 ? numsAry.length - 1 : quotient - 1;
      result += numsAry[ pos ];
      numsAry.splice( pos, 1 );
    }
    else {
      result += numsAry[ quotient ];
      numsAry.splice( quotient, 1 );
    }
    every = every / numsAry.length;
  }
  return result;
};
```

```
//优化后的算法,不会占用过多堆内存
var kthGrammar = function(N, K) {
  /*
  * 思路:根据第N-1行的内容推测第N行内容
  * 第N行的前半部分为N-1行,后半部分为N-1行逐位取反
  * 使用递归方式,判断K的值:
  * 如果K的值在N行长度的前半段,直接取N-1行的第K个
  * 如果K的值在N行长度的后半段,取N-1行的K - (N.length / 2)个
  * 最终迭代到第一行
  * */

  //获取第N行的第K个数,递归函数
  var getValue = function (N, K) {
    if (N === 1) {
      return 0;
    }
    if (K > getPow(N)) {
      return -1;
    }
    console.log('当前长度 ==>', N, getPow(N));
    if (K <= getPow(N) / 2) {
      return getValue(N - 1, K)
    } else {
      return changeValue(getValue(N - 1, K - (getPow(N) / 2)));
    }
  };

  //变换 0 -> 1, 1 -> 0
  var changeValue = function(value) {
    return !!value? 0: 1;
  };

  //获取2^的值
  var getPow = function(N) {
    var result = 1;
    for (var i = 1; i < N; i++) {
      result *= 2
    }
    return result;
  };

  return getValue(N, K);
};
```
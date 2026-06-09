# 20 - x的平方根

## 题目

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 **x 是非负整数**。

由于返回类型是整数，**结果只保留整数的部分**，小数部分将被舍去。

示例 1:

> 输入: 4
> 输出: 2

示例 2:

> 输入: 8
> 输出: 2
> 说明: 8 的平方根是 2.82842..., 
>      由于返回类型是整数，小数部分将被舍去。



## 解答

第一反应就是……

```js
var mySqrt = function(x) {
  return Math.floor(Math.sqrt(x));
};
```

> Runtime: 60 ms, faster than 98.95% of JavaScript online submissions for Sqrt(x).
>
> Memory Usage: 35.5 MB, less than 78.40% of JavaScript online submissions for Sqrt(x).

当然用原生api感觉有点太狡猾了。

### 二分法

参考：

> 作者：liweiwei1419
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/

思路就是把参数`x`当成一个数组。既然开平方的数不会超过其一半（例外是0-4）。就用二分法，从1到一半之间找开平方数，`target`就是`mid`的平方。

```js
var mySqrt = function(x) {
  if (x === 0) {
    return 0;
  } else if (x < 4) {
    return 1;
  }
  let left = 1;
  right = x / 2 + 1;
  while (left < right) {
    let mid = (left + right + 1) >>> 1;  // 取中位数的上边界
    let square = mid * mid;
    if (square > x) { 
      right = mid - 1;  // 因为答案是取地板，因此要抛弃掉右边的值，
    } else {
      left = mid;      // 取上边界，才能用left=mid，不然会死循环
    }
  }
  return left;
};
```

> Runtime: 88 ms, faster than 34.70% of JavaScript online submissions for Sqrt(x).
>
> Memory Usage: 35.6 MB, less than 68.54% of JavaScript online submissions for Sqrt(x).

### 牛顿法

> 参考
>
> 作者：LOAFER
>
> 链接：https://leetcode-cn.com/problems/two-sum/solution/niu-dun-die-dai-fa-by-loafer/

牛顿：没想到吧！开平方什么的，其实我早就想好解法了。

```JS
var mySqrt = function(x) {
  let ans = x;      // 开局随便定一个数
  while (ans * ans > x) {
    const next = (ans + x / ans) / 2;  // 防止死循环
    if (next === ans) {
      break;
    } else {
      ans = next;
    }
  }
  return Math.floor(ans);
};
```

> Runtime: 72 ms, faster than 82.88% of JavaScript online submissions for Sqrt(x).
>
> Memory Usage: 36 MB, less than 8.42% of JavaScript online submissions for Sqrt(x).

防止死循环，不加的话反例是5。函数会卡死在`2.23606797749979`

因为其平方是`5.000000000000001`，跳不出循环，而其运行完牛顿公式，还是它本身。

[无效的图片地址](http://ww3.sinaimg.cn/large/006tNc79ly1g51pfkq17nj30b908tglp.jpg)

原理就是这张图，即求$x^2=a$的正实根。就不断更新切线，不断算出逼近的点。
![image.png](https://pic.leetcode-cn.com/419c89266ab737083ca95511af314dc2f3d3baed62adc02a08e809749d789987-image.png)

### 解题思路
```js
维护一个后缀积的数组，每次 add 一个 num，让每一项乘这个 num 更新这个数组即可，
(遇到 num 为 0 的时候，直接把现有的所有填充为 0)
上面这行的操作可以不做，没有必要花费这个时间，直接记录最后一个为 0 的元素索引就好了
在本题中，其实保存所有元素的 arr 数组好像没什么用
```

### 代码

```javascript
var ProductOfNumbers = function() {
  this.arr = [];
  this.list = []; // 存储从当前位置开始到数组末尾的积
  this.notZero = 0; // arr 中第一个不为 0 的元素索引
};

/** 
 * @param {number} num
 * @return {void}
 */
/* 维护后缀积 */
ProductOfNumbers.prototype.add = function(num) {
  if (num === 0) {
    this.notZero = this.list.length;
  } else {
    for (let i = this.notZero; i < this.list.length; i++) {
      this.list[i] *= num;
    }
  }
  this.list.push( num );
  this.arr.push( num );
};

/** 
 * @param {number} k
 * @return {number}
 */
// 如果查找的最后 k 个数字有为 0 的元素，他们的积一定为 0，直接返回 0 即可
ProductOfNumbers.prototype.getProduct = function(k) {
  return this.list.length - k < this.notZero ? 0 : this.list[this.list.length - k];
};
```
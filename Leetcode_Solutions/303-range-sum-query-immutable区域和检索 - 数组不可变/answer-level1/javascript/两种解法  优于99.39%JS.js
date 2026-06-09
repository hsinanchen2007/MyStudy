### 一般的应用reduce每次求和

最后一个测试用例会超时
```JavaScript
var NumArray = function (nums) {
  this.temp = nums
};

NumArray.prototype.sumRange = function (i, j) {
  let t = this.temp.slice(i, j + 1),
    ret = 0;
  if (t.length == 1) {
    return t[0]
  }
  t.reduce(function (preValue, curValue) {
    return ret = preValue + curValue;
  })
  return ret
};
```

### 第一次new的时候就进行打表操作 优于99.39%

Your runtime beats 99.39 % of javascript submissions

Your memory usage beats 36.36 % of javascript submissions(44.9 MB)

```
var NumArray = function (nums) {
  this.temp = nums
  this.ret = []
  let tt = 0;
  for (let i = 0; i < nums.length; i++) {
    tt = tt + nums[i]
    this.ret.push(tt)
  }
};

NumArray.prototype.sumRange = function (i, j) {
  if (j == i) {
    return this.temp[i]
  }
  if (i == 0) {
    return this.ret[j]
  }
  return this.ret[j] - this.ret[i - 1]
};
```
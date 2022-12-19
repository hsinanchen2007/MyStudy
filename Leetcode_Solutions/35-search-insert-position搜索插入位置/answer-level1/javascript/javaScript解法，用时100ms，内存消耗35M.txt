```
var searchInsert = function (nums, target) {
  let res = -1;
//判断nums是否存在target的值
  res = indexValue(nums, target);

  //如果不存在目标值，插入
  if (res === -1) {
    // 先把目标值塞进数组
    nums.push(target);
    // 将数组排序
    nums.sort((a, b) => {
      if (a > b) return 1
      if (a < b) return -1
    });
    // 获取target的索引
    res = indexValue(nums, target);
  }
  return res
};

// 获取数组中某个元素的下标
let indexValue = (arr, target) => {
  let sub = -1;
  arr.map((val, i) => {
    if (val === target) sub = i
  })
  return sub
}
```
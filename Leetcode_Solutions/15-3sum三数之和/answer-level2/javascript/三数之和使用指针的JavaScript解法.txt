### 解题思路
这个解题思路实际上是从别人那里学过来的，最开始我自己的解法也是那种最low的循环，就不提了，写这个解题思路主要是为了验证自己的理解，如有谬误请指正；
首先这个题的重点在去重和减少循环次数。
1、关于去重就是先排序再从头开始进行循环就可以避免一部分重复。
2、其次使用两个分别指向首位和末尾的指针就可以减少循环次数。


### 代码

```javascript
function threeSum (nums) {
  const size = nums.length;
  let result = [];
  // 首先进行判断，为空或长度小于3不可能有解，应直接结束
  if (nums === null || size < 3) {
    return result;
  }
  // 从小到大的升序排序
  nums.sort((a, b) => a - b);
  for (let i = 0; i < size; i++) {
    // 排序后是负数在前的，如果出现正数则后面肯定无解，
    // 说明循环已经结束
    if (nums[i] > 0) {
      break;
    }
    // 判断是否重复，如果当前数与前一个数相等就算有解也会是重复的解，
    // 应跳过本次循环
    if (i > 1 && nums[i] === nums[i-1]) {
      continue;
    }
    // 定义两个指针
    // nums[i]为基准值，所以从i+1开始就行了
    let L = i + 1;
    // 右指针为最后一个值
    let R = size - 1;
    // L和R两个指针不断夹逼进行求解
    while (L < R) {
      const sum = nums[i] + nums[L] + nums[R];
      if (sum === 0) {
        // 如果和为0添加到结果数组
        result.push([nums[i], nums[L], nums[R]]);
        // 同时进行判断如果L和R指针的下一个值与当前值相同
        // 就算有解也是重复解，跳过继续进行循环
        while (nums[L] === nums[++L]) {}
        while (nums[R] === nums[--R]) {}
      } else if (sum < 0) {
        // 如果和小于0，说明当前的负数过大则L指针向后移
        L++;
      } else {
        // 如果和大于0，说明当前的正数过大则R指针向前移
        R--;
      }
    }
  } 
  return result;
}
```
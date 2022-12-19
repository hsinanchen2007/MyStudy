```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
  const result = [];    // 结果
  const f = (arr,vs) => {
    if(vs.length === arr.length){   // 若中间数组vs的长度等于原始数组长度则说明组完了
      result.push(vs);
      return;
    }
    const need = arr.filter(v => !vs.includes(v));  // 筛选可以放到当前中间数组后面的元素
    for(const n of need){
      f(arr,[...vs,n]); // 更新中间数组
    }
  }
  f(nums,[]);
  return result;
};
```

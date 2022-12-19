```
/**
 * @param {number[]} nums
 * @return {number}
 */
const majorityElement = function(nums) {
  let setArr = Array.from(new Set(nums)); // 获取输入数组中出现过的元素
  let times = []; // 存放每个元素的出现次数
  for (let i=0; i<setArr.length; i++) {
    let count = 0;
    nums.forEach(item => {
      if (item === setArr[i]) {
        ++count;
      }
    });
    times.push(count);
  }
  let index = 0; // 存放出现次数最多的索引
  for (let i=0; i<times.length; i++) {
    if (times[index] < times[i]) {
      index = i;
    }
  }
  return setArr[index];
};
```

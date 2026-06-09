### 解题思路
![image.png](https://pic.leetcode-cn.com/34d2e28d7625499bf5c3813ef7e8cdc61b707c6237d36385b52058b8bb2431bc-image.png)

 - 第一步，建立每个字母出现的次数（类hash表），同时确定出现次数最多的字母
 - 第二步，根据最大次数，判断是否能重构；能重构，用出现最多的字母建立一个二维数组；
 - 第三步，遍历剩余字母依次插入到二维数组中；
 - 第四部，遍历拼接得出答案；

** 重点注意思想在代码中已标记 **

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var reorganizeString = function(S) {
    
  const arr = S.split('');
  let target = arr[0];
  let cache = new Array(26).fill(0);
  let count = 1;
  for(let i = 0; i < arr.length; i++) {
      const str = arr[i];
      const code = str.charCodeAt() - 97;
      cache[code] = cache[code] + 1;
      if (cache[code] > count) {
          count = cache[code];
          target = str;
      }
      // 先选举法，看是否有大于百分之50；
      /* if (str === target) {
          count++;
      } else {
          count--;
          if (count < 0) {
              target = str;
              count = 1;
          } 
      } */
  }
  if (count > Math.ceil(arr.length / 2)) {
      return '';
  }

  const point = target.charCodeAt() - 97;
  // Note: 这里必须要主要的是必须fill 后，map操作才有效；
  // Note: new Array(count).fill([]), 这种骚操作有问题，相当于每个数组元素都指向了同一个[target]，相当于复制，后面push会
  // 造成同一个push，每一个遭殃
  const res = new Array(count).fill(target).map(a => [a]);
  
  // Note: 相对应字母已取出，直接清零，下面就可以少点判断；
  let j = 0;
  cache[point] = 0;
  for(let i = 0; i < 26; i++) {
      const ct = cache[i];
      if (ct === 0) {
          continue;
      }

      const str = String.fromCodePoint(i + 97);

      for (let k = 0; k < ct; k++) {
          res[j++%count].push(str);
      }
  }
  // reduce 常规骚操作
  return res.reduce((cur, pre) => cur + pre.join(''), '');
};
```
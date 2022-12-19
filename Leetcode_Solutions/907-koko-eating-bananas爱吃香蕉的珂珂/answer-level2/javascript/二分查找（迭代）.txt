### 解题思路
感觉最近疫情，大家都在耍Leetcode, 导致服务器运行速度变得很慢啊

![image.png](https://pic.leetcode-cn.com/3df781f950af713c425298e33c83f6cfb206ee83aa41172b8167748018187980-image.png)
### 代码

```javascript
/**
 * @param {number[]} piles
 * @param {number} H
 * @return {number}
 */
var minEatingSpeed = function(piles, H) {
  if (piles.length >= H) {
      // 循环找出最大的那一堆
      return piles.reduce((a, b) => Math.max(a, b));
  }
  // 排序，实际上不需要，可以直接用piles.reduce((a, b) => Math.max(a, b)) 找出最大值就行
  piles.sort((a, b) => b - a);
  let speedMax = piles[0];
  let speedMin = 1;

  let k = speedMax;
  // 二分查找；
  while (speedMax > speedMin) {
      k = Math.floor((speedMin + speedMax) /2);
      const hours = piles.reduce((total, pre) => total + Math.ceil(pre/k), 0);
      if (hours > H) {
        // [k + 1, speedmax]
        speedMin = k + 1;
      } else {
        // [speedMin, k]
        speedMax = k;
      }
      // console.log(speedMin, speedMax, k);
  }
  // 这里之所以取的是speedMin， 而不是K，是因为当speedMin = k + 1造成 speedMin === speedMax时，
  // 已经跳出了二分，所以这时K是不对的，那为什么speedMin 就对喃， 因为speedMax已经经过了验证
  return speedMin;
};
```
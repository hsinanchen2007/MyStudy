![image.png](https://pic.leetcode-cn.com/2b27810bf8f39a0deea65bd0b842cf181f2e07a77ccd52309d0dae09b476c3f6-image.png)

### 解题思路
```js
思路：
1.找到 A 和 B 所有可能的组合的和存到 map1 中
2.遍历 C 和 D 数组，对所有可能的和 c + d 取负值 -(c + d)， 查找是否在 map1
  中存在和为 c + d 的值，存在，就把存在此值的数量加到结果中
```

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */

var fourSumCount = function(A, B, C, D) {
  let map1 = new Map(),
      ans = 0,
      n = A.length;
  
  for (let i = 0; i < n; i++) {
    let a = A[i];
    for (let j = 0; j < n; j++) {
      let b = B[j];
      if (!map1.has( a + b )) {
        map1.set(a + b, 1);
      } else {
        map1.set(a + b, map1.get(a + b) + 1);
      }
    }
  }
  
  for (let k = 0; k < n; k++) {
    let c = C[k];
    for (let l = 0; l < n; l++) {
      let d = D[l];
      let sum = -(c + d);
      if (map1.has( sum )) {
        ans += map1.get( sum );
      }
    }
  }
  
  return ans;
};
```
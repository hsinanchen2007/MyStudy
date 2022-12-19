### 解题思路
![image.png](https://pic.leetcode-cn.com/8de1f0f1149b252e8dbd4840132f0b5fa7dd27b80abb40f961b1b938a9f6a66b-image.png)

1. 利用哈希表缓存权重计算结果
2. 计算出区间所有数的权重，将结果与当前值当作对象的值插入到数组中
3. 利用插入排序思路，插入位置即排序好的结果
4. 返回数组对应位置的数

### 代码

```javascript
/**
 * @param {number} lo
 * @param {number} hi
 * @param {number} k
 * @return {number}
 */
  var getKth = function(lo, hi, k) {
    const hash = {};
    function getWeight(x) {
      if (x === 1) return 0;
      if (x % 2 === 0) {
        x = x / 2;
        if (x === 1) return 0;
      } else {
        x = 3 * x + 1;
      }
      if (hash[x]) return hash[x];
      hash[x] = 1 + getWeight(x);
      return hash[x];
    }
    const res = [{weight: getWeight(lo) + 1, value: lo}];
    lo++;
    while (lo <= hi) {
      let weight = getWeight(lo) + 1;
      for (let i = res.length; i >= 0; i--) {
        if (res[i - 1] && res[i - 1].weight > weight) {
          res[i] = res[i - 1];
        } else {
          res[i] = {weight, value: lo};
          break;
        }
      }
      lo++;
    }
    return res[k - 1].value;
  };
```
### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
  //存储结果数组
  const results = [];
  /**
   * 构建哈希图
   * 其中
   * 值是频率
   * key是元素
   */
  const map = {};
  nums.forEach(n => {
    return map[n] ? (map[n] = map[n] + 1) : (map[n] = 1);
  });

  /**
   * 根据 频率
   * 对map的key数组进行排序
   */
  //首先获取所有的key
  const mapKey = Object.keys(map);
  const sortedKeys = mapKey
    .sort((a, b) => map[b] - map[a]);

  //取前几个的k的结果
  for (let i = 0; i < k; i++) {
    results.push(sortedKeys[i]);
  }

  return results;
};
```
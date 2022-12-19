### 解题思路
![image.png](https://pic.leetcode-cn.com/39064f7dcd6b7f64d00acbf3881f3837060453da9204aaadc8c47f1f00ff23c1-image.png)

1.使用两个map：map、checkRepeatMap
2.map存储数组中每个值出现的次数
3.遍历map的每个值的次数，如果checkRepeatMap中没有这个次数，那么把这个次数放进来，如果有，说明重复，直接返回false即可

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
  let map = new Map(),
      checkRepeatMap = new Map(),
      ans = true;
  
  for (let i = 0, len = arr.length; i < len; i++) {
    if (!map.has( arr[i] )) {
      map.set( arr[i], 1 );
    }
    else {
      map.set( arr[i], map.get( arr[i] ) + 1 );
    }
  }

  for (let [k, v] of map) {
    if (!checkRepeatMap.has( v )) {
      checkRepeatMap.set( v, 1 );
    }
    else {
      ans = false;
      break;
    }
  }

  return ans;
};
```
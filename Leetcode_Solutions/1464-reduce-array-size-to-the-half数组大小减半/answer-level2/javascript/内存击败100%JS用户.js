### 解题思路

建立一个哈希集，key为「数组元素」，value为「该元素出现的次数」。

然后把该哈希集转换成数组，以value为准降序排序。

len为原始数组的长度的一半（向上取整），当len从大到小减去哈希集的value，而最终累计值小于0时，返回res。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function(arr) {
  let map = new Map();
  let len = Math.ceil(arr.length/2);
  let valArr ;
  let res = 0;
  for(let i = 0 ; i < arr.length; i++) {
    if (!map.has(arr[i])) {
      map.set(arr[i], 1)
    } else {
      let num = map.get(arr[i]);
      map.set(arr[i], ++num);
    }
  }
  valArr = Array.from(map);
  valArr.sort(function(a,b){return b[1]-a[1]})
  for(let j = 0 ; j < valArr.length; j++) {
    res++;
    len -= valArr[j][1];
    if (len <= 0) {
      return res;
    }
  }   
};
```
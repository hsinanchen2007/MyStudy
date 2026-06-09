![image.png](https://pic.leetcode-cn.com/b26799a7892916cfd37c9aff714b16a7c8988b659e861d1f02e2619ad4523856-image.png)

### 解题思路
```javascript
  思路：
  1.先创建一个所有数值重复出现次数的数组
  2.逆序排序
  3.看看从这个数组中最少拿几个元素，才能拿到 >= 一半数量的元素
```

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */

/*
  下面的题解中 while 循环中操作数组次数太多，[].shift()，当每一个数都出现一次的时候，
  当用例为 arr.length = 10 的 5次方，那 [].shift 需要执行 Math.pow(10, 5) / 2 次
  非常恐怖
 */
var minSetSize = function(arr) {
  let map = new Map(), count = 0;
  
  for (let i = 0, len = arr.length; i < len; i++) {
    if (!map.has( arr[i] )) {
      map.set( arr[i], 1 );
    } else {
      map.set( arr[i], map.get( arr[i] ) + 1 );
    }
  }
  
  map = Array.from( map );
  
  map.sort((a, b) => b[1] - a[1]);
  
  let gets = 0, target = arr.length / 2;
  for (let i = 0, len = map.length; i < len; i++) {
    if (gets >= target) break;
    gets += map[i][1];
    count++;
  }
  
  return count;
};

/*
  思路：
  1.先创建一个所有数值重复出现次数的数组
  2.逆序排序
  3.看看从这个数组中最少拿几个元素，才能拿到 >= 一半数量的元素
*/
// var minSetSize = function(arr) {
//   let repeat = [], map = new Map(), count = 0;
  
//   for (let i = 0, len = arr.length; i < len; i++) {
//     if (!map.has( arr[i] )) {
//       map.set( arr[i], 1 );
//     } else {
//       map.set( arr[i], map.get( arr[i] ) + 1 );
//     }
//   }
  
//   map.forEach((v, k) => {
//     repeat.push( v );
//   });
  
//   repeat.sort((a, b) => b - a);
  
//   let gets = 0;
//   while (gets < arr.length / 2) {
//     gets += repeat.shift();
//     count++;
//   }
  
//   return count;
// };
```
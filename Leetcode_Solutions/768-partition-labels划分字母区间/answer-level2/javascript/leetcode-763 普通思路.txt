### 解题思路
1. 记录每个字母对应的出现最大位置
2. 再次循环
  1. 记录开始位置和结束位置
  2. 将结束位置值为max(end, 当前循环的字母最大位置)
  3. 如果 i == end 则  sta = end + 1 且记录一条数据

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[]}
 */
var partitionLabels = function(S) {
    let arr = [];
    let map = new Map();
    let sta = 0;
    let end = 0;

    // 第一步 记录每个字母对应的出现最大位置
    for (let i = 0; i < S.length; i ++) {
      map.set(S.slice(i, i + 1), i);
    }
    // console.log(map)
    // 第二大步 再次循环
    for (let i = 0; i < S.length; i ++) {
      // 将结束位置值为max(end, 当前循环的字母最大位置)
      end = Math.max(end, map.get(S.slice(i, i + 1)));
      if (i === end) {
        //  console.log(`end: ${end},   sta: ${sta}`);
        // 如果 i == end 则  sta = end + 1 且记录一条数据
        arr.push(end - sta + 1);
        sta = end + 1;
        // console.log(`arr: ${arr}`);
      }
    }

    return arr;

};
```
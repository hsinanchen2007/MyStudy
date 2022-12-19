### 解题思路

找出 `0-9` 相对应地英文中，每个单词独有的字母的次数：

1. `z` 只在 `0` 中出现；
2. `w` 只在 `2` 中出现；
3. `u` 只在 `4` 中出现；
1. `x` 只在 `6` 中出现；
1. `g` 只在 `8` 中出现；
1. `h` 在 `3` 和 `8` 中出现；
1. `f` 在 `5` 和 `4` 中出现；
1. `o` 在 `1`、`0`、`2` 和 `4` 中出现；
1. `v` 在 `7` 和 `5` 中出现；
2. `i` 在 `9`、`5`、`6` 和 `8` 中出现；

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var originalDigits = function(s) {
    let arr0 = s.match(/z/g);
    let arr2 = s.match(/w/g);
    let arr4 = s.match(/u/g);
    let arr6 = s.match(/x/g);
    let arr8 = s.match(/g/g);
    let arr3 = s.match(/h/g);
    let arr5 = s.match(/f/g);
    let arr1 = s.match(/o/g);
    let arr7 = s.match(/v/g);
    let arr9 = s.match(/i/g);

    let count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
    if(arr0) count0 = arr0.length;
    if(arr2) count2 = arr2.length;
    if(arr4) count4 = arr4.length;
    if(arr6) count6 = arr6.length;
    if(arr8) count8 = arr8.length;
    if(arr3) count3 = arr3.length - count8;
    if(arr5) count5 = arr5.length - count4;
    if(arr1) count1 = arr1.length - count0 - count2 - count4;
    if(arr7) count7 = arr7.length - count5;
    if(arr9) count9 = arr9.length - count5 - count6 - count8;
    return '0'.repeat(count0)+'1'.repeat(count1)+'2'.repeat(count2)+'3'.repeat(count3)+'4'.repeat(count4)+'5'.repeat(count5)+'6'.repeat(count6)+'7'.repeat(count7)+'8'.repeat(count8)+'9'.repeat(count9);
};
```
### 解题思路
#### 计算核心：
连续0的个数对应着能种花的个数：
其中如果是偶数，则除以2减1，例如 0000 则是 4/2 -1 = 1颗；
反之，则是 除以2取整，例如 000 则是 3/2 | 0 =  1颗

#### 连续0的计算
可以用正则计算出连续0组成的数组。

#### 边界情况处理：
地的两边可以视为再多一个空位，则可以视为0，没有种树，例如：

0      =>    000
00     =>    0000
001    =>    00010
1001   =>    010010

### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
  const flowerbedStr = `0${flowerbed.join('')}0`;

  let canPlaceCount = flowerbedStr.match(/0+/g).reduce((prev, str) => {
    const len = str.length;
    if (len % 2 === 0) {
      return prev + len / 2 - 1;
    } else {
      return (prev + len / 2) | 0;
    }
  }, 0);

  return canPlaceCount >= n;
};

```
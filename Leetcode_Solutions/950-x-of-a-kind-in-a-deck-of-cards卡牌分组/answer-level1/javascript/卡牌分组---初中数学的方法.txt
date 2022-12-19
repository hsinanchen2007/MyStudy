### 解题思路
思路：统计每种牌出现的次数，看它们之间是否有最大公约数，如果有，则可以分组

实现：
1. 根据题意，如果长度小于2，则不可分组
2. 统计所有牌的出现次数，时间复杂度O(n)
3. 找所有出现次数的最大公约数(因为限制了deck[i] 不超过10000，所以公约数不会超过100)

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
  if (deck.length < 2) return false;

  const arr = [];
  for (let i = 0; i < deck.length; i++) {
    if (arr[deck[i]]) {
      arr[deck[i]] += 1;
    } else {
      arr[deck[i]] = 1;
    }
  }
  const result = arr.filter(v => !!v);
  if (result.every(v => v === result[0])) return true;
  //1到100的质数
  const nums = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97
  ];


  for (let j = 0; j < nums.length; j++) {
    if (result.every(v => v % nums[j] === 0)) {
      return true;
    }
    continue;
  }
  return false;
};

```
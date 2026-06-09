![20200128102555.jpg](https://pic.leetcode-cn.com/019a0a0e2c1cb613f9dcf5c849a79ce29409888a2c01b002876fdea5612c4d03-20200128102555.jpg)

```javascript
/**
 * 1. 排序法
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) {
      return false;
    }

    var arrS = s.split('').sort();
    var arrT = t.split('').sort();

    return arrS.join('') === arrT.join('');
};

/**
 * 2. Hash
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    var map = new Map();
    var arrS = s.split('');
    var arrT = t.split('');

    if (arrS.length !== arrT.length) {
      return false;
    }

    for (var value of arrS) {
      var count = map.get(value);

      if (count) {
        map.set(value, count + 1);
      } else {
        map.set(value, 1);
      }
    }

    for (var value of arrT) {
      var count = map.get(value);

      if (count === 1) {
        map.delete(value);
      } else if (count > 1) {
        map.set(value, count - 1);
      }
    }

    return map.size === 0;
};



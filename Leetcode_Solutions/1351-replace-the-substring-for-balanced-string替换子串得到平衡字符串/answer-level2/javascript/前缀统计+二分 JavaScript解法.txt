思路: 由于可以替换成任意子串 也就是说 QQEQQ 中间的E 最后还是可以替换成E，所以只需要计算多了几个需要替换掉的字符(这里就是Q)，
只要得到这里多了3个q，那么就可以从串中找到最短的l,r使l到r中有3个Q就行了，高级点就是滑动窗口，这里我用前缀统计然后二分查找，复杂度O(nlogn).

```javascript
/**
 * @param {string} s
 * @return {number}
 */
//'Q', 'W', 'E', 'R'
var balancedString = function(s) {
  let Q = [0];
  let W = [0];
  let E = [0];
  let R = [0];
  // 统计所有字符数
  for (let i = 0; i < s.length; ++i) {
    if (i !== 0) {
      Q[i] = Q[i - 1];
      W[i] = W[i - 1];
      E[i] = E[i - 1];
      R[i] = R[i - 1];
    }
    if (s[i] === 'Q') {
      Q[i]++;
    }
    if (s[i] === 'W') {
      W[i]++;
    }
    if (s[i] === 'E') {
      E[i]++;
    }
    if (s[i] === 'R') {
      R[i]++;
    }
  }
  let targetLen = s.length / 4;
  // 计算各个字符多余的字符数，这里只需要关注多的就好了
  let Qmore = Q[s.length - 1] - targetLen;
  let Wmore = W[s.length - 1] - targetLen;
  let Emore = E[s.length - 1] - targetLen;
  let Rmore = R[s.length - 1] - targetLen;
  if (Qmore === Wmore && Emore === Rmore && Rmore === Wmore && Rmore === 0) {
    return 0;
  }
  let ans = 9 * 10e5;
  for (let i = 0; i < s.length; i++) {
    let hi = s.length;
    let lo = i;
    let mid = Math.floor((hi + lo) / 2);  // 二分查找最小串
    do {
      // 统计当前串各个字符有多少个
      let Qsub = Q[mid] - (i - 1 >= 0 ? Q[i - 1] : 0);
      let Wsub = W[mid] - (i - 1 >= 0 ? W[i - 1] : 0);
      let Esub = E[mid] - (i - 1 >= 0 ? E[i - 1] : 0);
      let Rsub = R[mid] - (i - 1 >= 0 ? R[i - 1] : 0);
      if (Qsub >= Qmore && Wsub >= Wmore && Esub >= Emore && Rsub >= Rmore) {
        ans = ans > mid - i + 1 ? mid - i + 1 : ans;
        if (hi - lo < 2) {
          break;
        }
        hi = mid;
      } else {
        if (hi - lo < 2) {
          break;
        }
        lo = mid;
      }
      mid = Math.floor((hi + lo) / 2);
    } while (true);
  }
  return ans;
};

console.log(balancedString('QQWE'));

```

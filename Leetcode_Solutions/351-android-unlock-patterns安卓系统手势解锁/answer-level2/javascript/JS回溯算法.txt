```
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var numberOfPatterns = function(m, n) {
  let result = 0;
  let S = {
    '1 3': 2, '4 6': 5, '7 9': 8, '1 7': 4, '2 8': 5, '3 9': 6, '1 9': 5, '3 7': 5,
    '3 1': 2, '6 4': 5, '9 7': 8, '7 1': 4, '8 2': 5, '9 3': 6, '9 1': 5, '7 3': 5
  };
  for (let i = m; i <= n; i++) helper(i);
  return result;

  function helper(n, l = undefined, s = '') {
    if (n === 0) return result += 1;
    for (let i = 1; i <= 9; i++) {
      if (l) {
        let k = l + ' ' + i;
        if (s.indexOf(i) === -1) {
          if (S[k] !== undefined) {
            if (s.indexOf(S[k]) > -1) helper(n - 1, i, s + i);
          } else {
            helper(n - 1, i, s + i);
          }
        }
      } else {
        helper(n - 1, i, s + i);
      }
    }
  }
};
```
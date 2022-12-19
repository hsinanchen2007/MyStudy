```
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
  const reg = new RegExp(`[${J}]`,'g');
  if(S.match(reg)){
    return S.match(reg).length;
  }
  return 0;
};

/*执行用时 :68 ms, 在所有 JavaScript 提交中击败了95.07%的用户
内存消耗 :34.1 MB, 在所有 JavaScript 提交中击败了42.60%的用户*/
```

## 第一版，使用hash结构存储s和t各个字符串出现的次数，然后遍历hash结构如果有相同字符出现的次数不同则不是异位词
> 104ms,35.9M
```javascript []
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if (s.length !== t.length) return false;
  let sObj = {};
  let tObj = {};
  for (let i = 0; i < s.length; i++) {
    if (sObj[s[i]]) sObj[s[i]]++;
    else sObj[s[i]] = 1;
    if (tObj[t[i]]) tObj[t[i]]++;
    else tObj[t[i]] = 1;
  }
  for (let char in sObj) {
    if (sObj[char] !== tObj[char]) return false;
  }
  return true;
};
```

## 第二版，转化为数组重新排序后再一次遍历对比每一项是否相同
> 160ms,38.2M
```javascript []
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if (s.length !== t.length) return false;
  let sArr = s.split('').sort();
  let tArr = t.split('').sort();
  for (let i = 0; i < s.length; i++) {
    if (sArr[i] !== tArr[i]) return false;
  }
  return true;
};
```

## 第三版，遍历一次，删除字符串中的所有该字符值，检查删除后长度是否相同
> 120ms,39.9M
```javascript []
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if (s.length !== t.length) return false;
  let temp = {};
  for (let i = 0; i < s.length; i++) {
    if (temp[s[i]]) continue;
    temp[s[i]] = 1;
    if (s.replace(new RegExp(s[i], 'g'), '').length !== t.replace(new RegExp(s[i], 'g'), '').length) return false;
  }
  return true;
};
```
## 还是第三版的思路，但是可以不使用临时对象来辅助
> 84ms,38.5M
```javascript []
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if (s.length !== t.length) return false;
  while (s.length > 0) {
    if (s.length !== t.length) return false;
    t = t.replace(new RegExp(s[0], 'g'), '');
    s = s.replace(new RegExp(s[0], 'g'), '');
  }
  if (t.length !== 0) return false;
  return true;
};
```
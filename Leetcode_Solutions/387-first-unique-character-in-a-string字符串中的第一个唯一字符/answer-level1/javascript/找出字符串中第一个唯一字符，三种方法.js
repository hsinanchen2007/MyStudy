## 第一版，先遍历一次字符串找到所有字符及其出现的下标，再遍历对象返回第一个只出现一次的字符下标。（for in遍历对象时，如果键是string类型则会按写入顺序遍历
> 148ms,43.2M
```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
  const sObj = {};
  for (let i = 0; i < s.length; i++) {
    if (sObj[s[i]]) sObj[s[i]].push(i);
    else sObj[s[i]] = [i];
  }
  for (let i in sObj) {
    return sObj[i][0];
  }
  return -1;
};
```

## 第二版，删去重复出现的字符，查询剩余字符串中第一个字符在原字符串中的下标
> 220ms,41.7M
```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
  let sTemp = s;
  const sObj = {};
  for (let i = 0; i < sTemp.length;) {
    if (sObj[sTemp[i]] >= 0) {
      sTemp = sTemp.replace(new RegExp(sTemp[i],'g'),'');
      i--;
    } else {
      sObj[sTemp[i]] = i;
      i++;
    }
  }
  return s.indexOf(sTemp[0]);
};
```

## 第三版，一边遍历一边查询（两种查询方法）
> 108ms,38.4M
1. 从后往前查当前字符值的下标是否与当前下标相等。108ms,38.4M
2. 遍历中使用当前字符值分割字符串后的数组长度是否刚好为2。252ms,49M
```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
  const sObj = {};
  for (let i = 0; i < s.length; i++) {
    if (sObj[s[i]]) continue;
    // if (s.split(s[i]).length === 2) return i; // 252ms,49M
    if (s.lastIndexOf(s[i]) === i) return i; // 108ms,38.4M
    else sObj[s[i]] = 1;
  }
  return -1;
};
```

-----
### 看了题解之后再来把第一版优化一下，不用把每个字符的所有出现下标都保存，只需把第一次出现的下标保存即可。重复出现时则把保存的值设为-1。相比原第一版哒哒的减少了空间复杂度
> 132ms,38.2M
```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
  const sObj = {};
  for (let i = 0; i < s.length; i++) {
    if (sObj[s[i]] >= -1) sObj[s[i]] = -1;
    else sObj[s[i]] = i;
  }
  for (let i in sObj) {
    if (sObj[i] >= 0) return sObj[i];
  }
  return -1;
};
```
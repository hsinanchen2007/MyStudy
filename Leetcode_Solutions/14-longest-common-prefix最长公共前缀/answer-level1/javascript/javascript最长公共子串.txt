### 1. 暴力循环
>用数组的第一个字符串为基准进行遍历,第一层循环是首个字符串的长度,第二层循环是数组的长度,如果首个字符串的首个字母与二个字符串的首字母相同,则继续遍历数组的下一项的对应字母,如果不同,则返回首个字符串的[0, j)处的字符串,最后如果全部字符串相同,则循环不会走到if语句的return，也就没有返回值,所以当函数执行到循环的最外层时,就说明当前数组的所有元素都相同,则返回数组的首个字符串即可

```
/**
 * @description 暴力法求解
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (strs.length === 0) return '';
  for (let j = 0; j < strs[0].length; j++) {
    for (let i = 0; i < strs.length - 1; i++) {
      if (strs[i][j] !== strs[i + 1][j]) return strs[0].slice(0, j);
    }
  }
  return strs[0];
};

```

### 2. 数组首个字符串比较切割
>将返回值ans首先设置为数组的首个字符串,从数组的第二项开始循环,每次都将ans与当前的循环项进行比较,更新ans的值,循环结束返回ans即为所求

```
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (strs.length === 0) return '';
  let ans = strs[0];
  for (let i = 1; i < strs.length; i++) {
    let j = 0;
    while (j !== ans.length) {
      if (ans[j] === strs[i][j]) {
        j++;
      } else {
        ans = ans.slice(0, j);
        if (ans === '') return ans;
      }
    }
  }
  return ans;
};

```
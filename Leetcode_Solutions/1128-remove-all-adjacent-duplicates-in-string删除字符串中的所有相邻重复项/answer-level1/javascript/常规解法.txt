### 执行结果
执行用时 :
108 ms
, 在所有 JavaScript 提交中击败了
81.64%
的用户
内存消耗 :
41.1 MB
, 在所有 JavaScript 提交中击败了
100.00%
的用户

### 解题思路
- 新建一个数组result,然后遍历S。
- result为空则push，否则和result最后一位做比较，相同则pop,否则push

### 
```javascript
var removeDuplicates = function(S) {
  let arr = S.split("");
  let result = [];

  arr.forEach((item, index) => {
    if (!result.length) {
      result.push(item);
    }else {
      if (item === result[result.length -1]) {
        result.pop();
      } else {
        result.push(item);
      }
    }
  });

  return result.join('')
};
```
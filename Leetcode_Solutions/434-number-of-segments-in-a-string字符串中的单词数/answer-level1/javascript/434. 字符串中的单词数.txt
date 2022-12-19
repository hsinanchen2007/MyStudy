### 解题思路
+ 过滤替换代码中的`:`与继续的空格，
+ 并去掉头尾的空格，再进行`split`切割，
+ 返回数组的长度。。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
  s = s.replace(/:|(\s+)/g," ").trim();
  if(!s){
    return 0
  };
  
  let res = s.split(/\s+/);
  return res.length;
};
```
/.. 弹出，/. 无动作，/abc 压入

```javascript
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
  let result = [];
  let pathArr = path.split("\/");
  pathArr.forEach(val => {
    if (val === "..")
      result.pop();
    else if (val !== "" && val !== ".")
      result.push(val)
  })
  return "/" + result.join("/")
};
```
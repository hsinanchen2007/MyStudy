

![image.png](https://pic.leetcode-cn.com/b09cb016ead741aa805bbab730ad9011b29bf18cf1cc0d7bf9994a10b81f8ab3-image.png)
```
var simplifyPath = function(path) {
  let myRe = /(\/\.*[\w]+)|(\/\.\.+)/g;
  let arr;
  let resArr = [];
  while( (arr= myRe.exec(path)) !== null) {
    if (arr[0] === '/..') {
      resArr.pop();
    } else {
      resArr.push(arr[0]);
    }
  }

  return resArr.length > 0? resArr.join(''): '/';
};
```


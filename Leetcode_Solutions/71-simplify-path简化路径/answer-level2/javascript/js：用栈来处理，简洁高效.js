按'/'切割字符串成数组，对数组遍历：
1. 空字符串不处理
2. 遇到'.'不处理
3. 遇到'..'，result pop一个元素
4. 其他push到result

最后数组转成字符串，记得前面补上'/'，大功告成。
上代码：

```javascript
function simplifyPath(path) {
  const arr = path.split('/');
  const result = [];
  for (let i = 0; i < arr.length; i++) {
    const item = arr[i];
    if (item && item !== '.' && item !== '..') {
      result.push(item);
    } else if (item == '..') {
      result.pop();
    }
  }
  return '/' + result.join('/');
};
```

### 解题思路
解法比较简单粗暴，主要转换字符串为数组，用栈对数组进行操作。
1. 如果遇到`..`则进行pop操作
2. 如果遇得空串或者`/`，则跳过操作
3. 其它则进行压栈，push操作
4. 重复上述操作知道遍历完数组


如果栈为空，则返回`'/'`

否则就把栈中元素用`/`拼接起来，得到结果

![image.png](https://pic.leetcode-cn.com/fb138fc16b139886dac07463c1f64fe4c74b67bdb2d68fb7b79af42601b3a674-image.png)



### 代码

```javascript
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
  const stack = [];
  const pathFrags = path.split('/');

  for (let i = 0; i < pathFrags.length; i++) {
    const currentFrag = pathFrags[i]
    if (currentFrag) {
      if (currentFrag === '..') {
        stack.pop();
      } else if (currentFrag === '' || currentFrag === '.') {
        continue;
      } else {
        stack.push(currentFrag);
      }
    }
  }

  if (!stack.length) {
    return '/';
  }

  return `/${stack.join('/')}`
};
```
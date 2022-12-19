![happy.png](https://pic.leetcode-cn.com/930fd8e7f87e50815c10bde7c33f7878ea973ce04f03beae8824ffb9eea82fbd-happy.png)

ps: 前端api搬运工用很土的方法做的提交, 应该是用`JavaScript`提交的人比较少, 所以才有的双一百

### 思路
如`ababab`, 字符串长度为6

假设最长快乐前缀为5, 前缀为`ababa`, 后缀为`babab`, 两者不相等, 不满足条件
假设最长快乐前缀为4, 前缀为`abab`, 后缀为`abab`, 两者相等, 满足条件, 即为所求

### 代码
```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
  if (s.length <= 1) {
    return ''
  } else {
    let len = s.length - 1
    while (len > 0) {
      const prefix = s.substr(0, len)
      const postfix = s.substr(s.length - len, len)
      if (prefix === postfix) {
        return prefix
      }
      --len
    }
    return ''
  }
};
```

### 硬广
欢迎关注我的掘金, [https://juejin.im/user/59a4b413518825244442619a/posts](https://juejin.im/user/59a4b413518825244442619a/posts), 里面有前端算法渣渣本渣的刷题总结, 欢迎点赞和来撩
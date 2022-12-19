### 解题思路

```js
如: test.email+alex@leetcode.com
以 @ 分隔 得到 list = ['test.email+alex', 'leetcode.com']

再把 test.email+alex 去除. => testemail+alex  截取 + 号 前面字符 => testemail

此时 list = ['testemail','leetcode.com'] ,再以 @ 拼接回去 => testemail@leetcode.com

```


### 代码

```javascript
/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    return [...new Set(emails.map(item => {
      let list = item.split('@')
      list[0] = list[0].replace(/\./g,'').split('+')[0]
      return list.join('@')
    }))].length
};
```
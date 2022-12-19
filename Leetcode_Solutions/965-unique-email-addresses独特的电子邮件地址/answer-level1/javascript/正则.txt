### 解题思路
只管用正则替换@前面部分,利用Set的特性,往里面add,最后返回size

### 代码

```javascript
/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    let hashSet = new Set()
    emails.forEach(item=>{
      let arr = item.split('@')
      arr[0] = arr[0].replace(/\+.*/, '').replace(/\./g, '')
      hashSet.add(`${arr[0]}@${arr[1]}`)
    })
    return hashSet.size
};
```
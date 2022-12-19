*法一：正则*

```js
var numUniqueEmails = function(emails) {
    let res = []
    // 匹配+和+后面的
    let pat = /(?=\+).*/
    // 匹配@左边的部分
    let pat2 = /.*(?=@)/
    // 匹配@右边的部分
    let pat3 = /(?<=@).*/
    emails.forEach(item => {
        let left = item.match(pat2)[0]
        let right = item.match(pat3)[0]
        left = left.replace(pat, '').replace(/\./g, '')
        res.push(`${left}@${right}`)
    })
    return new Set(res).size
};
```

[(?<=)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Regular_Expressions/Assertions?from=singlemessage)

```js
var numUniqueEmails = function(emails) {
    let res = []
    // 匹配+和+后面的
    let pat = /(?=\+).*/
    for (let item of emails) {
        let [left, right] = item.split('@');
        left = left.replace(pat, '').replace(/\./g, '')
        res.push(`${left}@${right}`)
    }
    return new Set(res).size
};
```


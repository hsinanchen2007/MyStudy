![image.png](https://pic.leetcode-cn.com/3a9eb023807ee9b4c985fdca6f309aea7ad21717722feb8a6c10cbc27ad1cb45-image.png)

```
var removeDuplicates = function(str) {
    let res = [];
    for (let i = 0; i < str.length; i++) {
        let flag = res[res.length - 1] ? res[res.length - 1] : '';
        if (str[i] == flag) {
            res.pop();
        } else
            res.push(str[i]);
    }
    return res.join('')
};
```

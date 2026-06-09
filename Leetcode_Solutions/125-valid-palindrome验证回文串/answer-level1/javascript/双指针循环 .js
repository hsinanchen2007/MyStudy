
```js
var isPalindrome = function(s) {
    if(s === '') return true
    let reg = /[^A-Za-z0-9]/g
    // 先用正则处理字符串，去除无用字符并转换成小写
    s = s.replace(reg, '').toLowerCase()
    let len = s.length
    let isPalind = true
    // 头尾两个指针循环对比
    for(let i=0,j=len-1;i<j;i++,j--){
        if(s.charAt(i) !== s.charAt(j)){
            isPalind = false
        }
    }
    return isPalind
};
```
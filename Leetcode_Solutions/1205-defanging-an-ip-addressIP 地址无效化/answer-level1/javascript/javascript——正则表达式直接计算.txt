正则表达式版本：

```javascript
var defangIPaddr = function(address) {
    return address.replace(/\./g,"[.]")
};
```

非正则表达式版本：  
时间复杂度为：O(n)
空间复杂度为：O(n)，需要将address拆分为一个长度为n的字符数组

```javascript
var defangIPaddr = function(address) {
    address=address.split("");
    for(let i=0;i<address.length;i++){
        if(address[i]==='.'){
            address[i]='[.]';
        }
    }
    return address.join("");
}

```
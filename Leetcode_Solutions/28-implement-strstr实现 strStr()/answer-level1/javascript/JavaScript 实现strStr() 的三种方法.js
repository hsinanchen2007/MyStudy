解一：
> 本能`indexOf`，这不叫投机取巧，毕竟现成的轮子，不用白不用。

```js
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle)
};
```

解二：
> 直接`indexOf`未免有些过于轻佻，所以再双层`for`循环嵌套来一个。当首位匹配时，循环检查后几位是否相同。不过这个速度嘛，就不敢恭维了。

```js
var strStr = function(haystack, needle){
    if (needle==="") return 0
    for(var i=0;i<haystack.length;i++){
        if(haystack[i]===needle[0]){
            var flag = true;
            for (var j=1;j<needle.length;j++){
                if (haystack[i+j]!=needle[j]){
                    flag = false
                    break;
                }
            }
            if (flag) return i
        }
    }
    return -1
};
```

解三：
> 突然记起来`substring`的存在，这样就可以少一次内层循环了。速度和`indexOf`差不多。

```js
var strStr = function (haystack, needle) {
    if (needle === "") return 0
    for (var i = 0; i < haystack.length; i++) {
        if (haystack[i] === needle[0]) {
            if (haystack.substring(i, i + needle.length) === needle) return i;
        }
    }
    return -1
};
```

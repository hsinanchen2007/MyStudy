小白的解法  不知在内存方面是否有未考虑到的地方
请前辈指教

```
var reverse = function(x) {
    let num = 0
    while(x != 0) {
        num = num * 10 + (x % 10)
        x = parseInt(x / 10)
    }
    return num
}
```

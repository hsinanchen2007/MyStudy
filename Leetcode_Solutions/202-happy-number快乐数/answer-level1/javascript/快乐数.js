**成功的例子(19)**

- 19 => 1 + 81
- 82 => 64 + 4
- 68 => 36 + 64
- 100 => 1 + 0 + 0

**失败的例子(20)**

- 20 => 4 + 0
- 4 => 16
- 16 => 1 + 36
- 37 => 9 + 49
- 58 => 25 + 64
- 89 => 64 + 81
- 145 => 1 + 16 + 25
- 42 => 16 + 4
- 20 可以看到, 20再次重复出现了, 所以永远不可能等于1

那思路就是将每次求的平方和存入数组，判断重复, 就return false


```js
var isHappy = function(n) {
    var result = [];
    while(sum !== 1){
        var arr = n.toString().split('');
        var sum = 0;
        for (let i = 0; i < arr.length; i++) {
            sum += Math.pow(parseInt(arr[i]),2)
        }
        if (result.indexOf(sum) > -1) {
            return false
        }
        n = sum;
        result.push(sum); 
    }
    return true
};
```



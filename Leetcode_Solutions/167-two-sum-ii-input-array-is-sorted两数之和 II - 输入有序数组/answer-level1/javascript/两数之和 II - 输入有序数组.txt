*法一：暴力双循环*

缺点：速度太慢

```js
var twoSum = function(numbers, target) {
    var len = numbers.length;
    var result = [];
    for(var i = 0; i < len - 1; i++) {
        for(var j = i + 1; j < len; j++) {
            if (numbers[i] + numbers[j] === target) {
                result.push(i+1, j+1)
            }
        }
    }
    return result
};

var numbers = [2, 7, 11, 15];
var target = 9;
console.log(twoSum(numbers, target))
```

*法二：双指针*

```js
var twoSum2 = function(numbers, target) {
    var l = 0;
    var r = numbers.length - 1;
    while(l < r) {
        if(numbers[l] + numbers[r] === target) {
            return [l+1,r+1]
        } else if (numbers[l] + numbers[r] < target) {
            l++
        } else {
            r--
        }
    }
};
```



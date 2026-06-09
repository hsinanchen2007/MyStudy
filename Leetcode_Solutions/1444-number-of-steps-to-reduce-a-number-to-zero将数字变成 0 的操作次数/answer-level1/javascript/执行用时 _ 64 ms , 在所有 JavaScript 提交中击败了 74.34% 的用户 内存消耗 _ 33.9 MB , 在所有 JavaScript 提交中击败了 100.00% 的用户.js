```
var numberOfSteps = function (num) {
    let ans = 0
    while (0 < num) {
        if (num % 2 === 0) {
            num = num / 2
            ans++
        } else {
            num = num - 1
            ans++
        }
    }
    return ans
};
```

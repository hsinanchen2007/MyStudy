执行用时 : 68 ms, 在所有 JavaScript 提交中击败了 98.42% 的用户
内存消耗 : 34.4 MB, 在所有 JavaScript 提交中击败了 100.00% 的用户

```javascript []
var distributeCandies = function(candies, num_people) {
    var res = Array(num_people).fill(0);
    var current = 1;
    var index = 0;
    while (candies) {
        if (candies < current) {
            res[index] += candies;
            break;
        }
        res[index] += current;
        index = (index + 1) % num_people;
        candies -= current++;
    }
    return res;
};
```

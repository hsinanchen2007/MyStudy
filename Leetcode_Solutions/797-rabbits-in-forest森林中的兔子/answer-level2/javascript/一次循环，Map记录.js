### 解题思路
要想使得兔子数量最小，那么尽量将报同样数量的视为同一颜色，但为了不矛盾，需要使用map记录对应颜色兔子最大的出现次数
报0的兔子一定是独一无二的直接++

### 代码

```javascript
var numRabbits = function(answers) {
    let map = new Map(), res = 0;

    for (let a of answers) {
        if (a == 0) {
            res++;
        } else if (!map.has(a)) {
            res += (1 + a);
            map.set(a, a);
        } else {
            map.set(a, map.get(a) - 1);
            if (map.get(a) == 0) {
                map.delete(a);
            }
        }
    }
    return res;
};
```
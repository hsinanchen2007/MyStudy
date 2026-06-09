### 解题思路
维护一个`length = 10`的窗口，每次将窗口内的字符串存进`map`中
当第二次遇到同样字符串，+1即可

### 代码

```javascript
var findRepeatedDnaSequences = function(s) {
    if (s.length < 11) return [];
    let n = s.length, map = new Map(), left = 0, right = 10, res= [];

    while (right <= n) {
        let cur = s.substring(left, right);

        map.set(cur, map.has(cur) ? map.get(cur) + 1 : 1);
        left++;
        right++;
    }

    for (let [k, v] of map) {
        if (v > 1) res.push(k);
    }
    return res;
};
```
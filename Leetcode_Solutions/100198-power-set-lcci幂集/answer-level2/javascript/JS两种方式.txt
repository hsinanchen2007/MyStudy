- 法一
```
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
    let sets = [...new Set(nums)] // 数组去重
    let rets = [[]] //初始化
    let l = sets.length
    for (let i = 0; i < l; i++) {
        let turn = rets.map(v => [...v, sets[i]])
        rets = rets.concat(turn)
    }
    return rets
};

```

- 法二

```

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
    let sets = [...new Set(nums)]
    let rets = [[]]
    let track = function (rets) {
        if (!sets.length) {
            return rets
        }
        let current = sets.shift()
        let turn = rets.map(v => [...v, current])
        return track(rets.concat(turn))
    }
    return track(rets)
};
```


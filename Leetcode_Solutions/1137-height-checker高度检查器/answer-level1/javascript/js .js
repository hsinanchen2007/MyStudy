思路：
排序，然后对照，如遇到不同的元素就++
```
/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function (heights) {
    let map = {} //声明变量用来保存heights每个相同元素的个数；----主要利用了{}如果key是数字，会自动升序排序（换成数组也可以）
    for(let i of heights){
        if(!map[i]){
            map[i] = 0
        }
        map[i]++
    }
    let count = 0;
    let t = 0
    for(let j in map){
        while(map[j]-- > 0){
            if (heights[t++] !== j) count++;
        }
    }
    return count
};
```
二：
```
var heightChecker = function (heights) {
    let tmp = [...heights]
    tmp.sort((a,b)=>a-b)
    let count = 0;
    for (let i = 0, len = heights.length; i < len; i++){
        if (heights[i] !== tmp[i]){
            count++
        }
    }
    return count
};
```


### 解题思路
![image.png](https://pic.leetcode-cn.com/f139f981363524e349d6cfe05181515cd00bf61a0f47b4d98e27ed6ecddc08c7-image.png)
- 先排序，降低循环
- 先求得最小值
- 通过判断差值是否等于最小值，如果是加入 res中


### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    let min_val = Number.MAX_VALUE
    let diff = 0
    let res = []
    arr.sort((a,b)=>a-b)
    for(let i = 1; i<arr.length; i++){
        diff = arr[i] - arr[i-1]
        if(diff < min_val){
        min_val =  diff
    }
}
    for(let j=1; j<arr.length; j++){
        if((arr[j] - arr[j-1]) == min_val) {
            res.push([arr[j-1],arr[j]])
    }
}
    return res
};

```
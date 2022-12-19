### 解题思路
此处撰写解题思路

### 代码
1、对arr进行升序排序
2、遍历找出最小绝对差
3、遍历找出符合最小绝对差的值，push进res
```javascript
/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    let min_val = Number.MAX_VALUE
    let len = arr.length
    let diff = 0
    let res = []
    arr.sort((a,b)=>a-b)
    for(let i = 0; i<len; i++){
        diff = arr[i] - arr[i-1]
        if(diff < min_val) min_val =  diff
    }
    for(let j=1; j<len; j++){
        if((arr[j] - arr[j-1]) == min_val) res.push([arr[j-1],arr[j]])
    }
    return res
};
```
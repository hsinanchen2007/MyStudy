### 解题思路
![image.png](https://pic.leetcode-cn.com/c5dd91f42d3308bcdb8171aa813167cc5b88fe882fb027653b744e704db5e400-image.png)


### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    let ret = [];
    arr.sort(function (a,b){return a-b;});
    for(let i=0;i<k;i++){
        ret.push(arr[i]);
    }
    return ret;
};
```
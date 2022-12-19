### 解题思路
![image.png](https://pic.leetcode-cn.com/755043117adc0a874371f0394ddfb59003fcfddcb002f81c2c8e57010b2c8e9e-image.png)

- find() 查找最小的索引数
- 通过遍历，然后通过 Array.filter进行遍历，将得到的 count 加到 arr中，return arr


### 代码

```javascript
/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    let arr = []
    for(let i = 0; i <queries.length; i++){
        let pre = find(queries[i])
        let count = words.filter(item => {
            let next = find(item)
            return next > pre
        })
        if(count.length >= 0){
            arr.push(count.length)
        }
    }
    return arr
};

function find(x){
    let tmp = x.split('').sort()
    let num = 0
    for(let i = 0; i < tmp.length; i++){
        if(tmp[i] === tmp[0]){num++}
        else{break}
    }
    return num
}
```
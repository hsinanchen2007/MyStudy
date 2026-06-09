### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let i = 1, res = [];
    while ((i*i + i) < 2*target) {
        if ((target - (i*i  + i)/2) % (i+1) === 0) {
            let x = (target - (i*i  + i)/2) / (i+1);
            res.push([...Array(i+1)].map((v, index)=> x+ index));
        }
        i++
    }
    return res.reverse();
};
```
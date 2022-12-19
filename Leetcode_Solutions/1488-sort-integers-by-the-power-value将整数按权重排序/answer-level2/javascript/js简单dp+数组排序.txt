### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} lo
 * @param {number} hi
 * @param {number} k
 * @return {number}
 */
var getKth = function(lo, hi, k) {
    let dp = [];
    dp[1] = 1;
    let arr = [];
    for(let i = lo; i <= hi; i++) {
        arr.push(i);
    }
    let query = (number) => {
        if(dp[number]) {
            return dp[number];
        }
        if(number % 2 == 0) {
            dp[number] = query(number/2) + 1;
        } else {
            dp[number] = query(3*number+1) + 1;
        }
        return dp[number];
    }
    arr.sort((a, b) => {
        if(query(a) != query(b)) {
            return query(a)-query(b);
        } else {
            return a-b;
        }
    });
    return arr[k-1];
};
```
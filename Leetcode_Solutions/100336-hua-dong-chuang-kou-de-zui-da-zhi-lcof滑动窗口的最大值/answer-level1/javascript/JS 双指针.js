### 代码

```javascript

var maxSlidingWindow = function(nums, k) {
    let res = [];
    if(nums == null || k<1) return []
    let low = 0,
        high = low + k -1;
    while(high < nums.length){
        let temp = nums.slice(low, high + 1);
        let max = Math.max(...temp);
        res.push(max);
        low++;
        high++;
        temp = null;
    }
    return res
};

```
计算每个数字二进制每位的和，若不能被3整除，则在该为存在一个异位数**1**。统计这个数的二进制异位数，转化为10进制即可。

```javascript
var singleNumber = function(nums) {
    let array = new Array(32).fill(0);
    for (let item of nums) {
        let index = 0;
        do {
            if (item & 1) array[ index ]++
            index++;
        } while(item >>= 1)
    }
    let pow = 1;
    return array.reduce((total, item) => {
        total += (item % 3 * pow);
        pow *= 2;
        return total;
    }, 0)
};
```

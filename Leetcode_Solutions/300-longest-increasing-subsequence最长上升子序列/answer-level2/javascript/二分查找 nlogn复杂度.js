参考精选的java代码实现javascript，代码比较简单些

```javascript
var lengthOfLIS = function(nums) {
    let n = nums.length;
    let res = 0
    let tail = Array(n).fill(0)
    nums.forEach(num => {
        let i = 0
        let j = res
        while (i < j) {
            let m = Math.floor((i + j) / 2)
            if (tail[m] < num) i = m + 1 
            else j = m
        }
        tail[i] = num
        if (res === j) res++
    })
    return res
};
```
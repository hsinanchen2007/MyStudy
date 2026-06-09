**思路：**

1. 如果是顺序的那么灯就变蓝，所有的已经开着的蓝灯肯定符合等差数列的求和公式
2. 将已经打开的灯的序号的和与等差数列的和对比，如果相等，那么就符合条件count++

![image.png](https://pic.leetcode-cn.com/b32ea43c74bc852e1d1bbda172d0c5595b9fc92305f84d80a81545cc31f9f70d-image.png)

```
/**
 * @param {number[]} light
 * @return {number}
 */
var numTimesAllBlue = function(light) {
    let count = 0 ,sum = 0
    for(let i = 0 ;i<light.length;i++){
        sum+=light[i]
        let len = i+1,addSum  = len*(len+1)/2
        if(sum ==addSum){
            count++
        }
    }
    return count
};
```

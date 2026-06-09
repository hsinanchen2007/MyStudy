### 解题思路
![image.png](https://pic.leetcode-cn.com/b34e90f865200b97be0b4828eb2e62f2a803a567e9e23b948b34a7f65b93c829-image.png)

1. 两次循环 一个判断

### 代码

```javascript
/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    let num = 0;
    for(let i = 0; i < time.length; i++){
        for(let j = i+1; j < time.length; j++){
            if((time[i] + time[j]) % 60 == 0){
                num++
            }
        }
    }
    return num
};
```
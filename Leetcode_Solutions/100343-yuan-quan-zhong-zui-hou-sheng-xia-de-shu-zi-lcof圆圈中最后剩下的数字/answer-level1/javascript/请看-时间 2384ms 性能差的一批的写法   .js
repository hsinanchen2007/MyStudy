### 解题思路
    一开始无脑尝试  终于成功了  但性能有点差 惭愧 
![E4C759F7-0D6B-4480-8F6D-66BBC699660B.png](https://pic.leetcode-cn.com/e00c92bdba99d3fca6c060a6490b007c5631fb07e520d9d8344314be3cca5712-E4C759F7-0D6B-4480-8F6D-66BBC699660B.png)

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    let arr = [...(new Array(n).keys())];
    let lastIdx = m - 1;
    while(arr.length > 1){
        if(arr.length == lastIdx){
            lastIdx = 0;
        }else{
            let num = (lastIdx % arr.length);
            lastIdx = num == 0 ? 0 : num;
        }
        arr.splice(lastIdx , 1)
        lastIdx += m - 1
    }
    return arr[0]
};
```
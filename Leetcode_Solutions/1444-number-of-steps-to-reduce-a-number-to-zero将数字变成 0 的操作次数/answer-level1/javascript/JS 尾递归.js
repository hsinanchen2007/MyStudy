### 解题思路
&emsp;&emsp;偶数除2，奇数减一，累加cnt，操作数为0时返回cnt。

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    function dfs(num, cnt){
        if(num == 0) return cnt;
        return dfs(num % 2 == 0 ? num / 2 : num - 1, cnt + 1);
    }
    return dfs(num, 0);
};
```
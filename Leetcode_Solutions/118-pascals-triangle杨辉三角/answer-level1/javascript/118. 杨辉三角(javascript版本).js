# 动态规划思想
简单的使用dp table来解决，状态转移方法为：`row[i][j] = row[i - 1][j-1] + row[i - 1][j]`。
![PNG图像.png](https://pic.leetcode-cn.com/47ad8afb2421ff316b33417f8d1cd4c1a94e522817bba11efc85ad2e8e94500c-PNG%E5%9B%BE%E5%83%8F.png)

因此，代码就很简单了:
```javascript
var generate = function(numRows) {
    let res = [];
    for(let i = 0; i < numRows; i++) {
        let temp = Array(i+1);
        temp[0] = 1;
        temp[i] = 1;
        for(let j = 1; j < i; j++) {
            temp[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push(temp);
    }
    
    return res;
};

```
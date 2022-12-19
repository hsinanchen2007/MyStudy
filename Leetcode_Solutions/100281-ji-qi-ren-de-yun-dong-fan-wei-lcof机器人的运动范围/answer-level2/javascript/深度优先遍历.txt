### 解题思路
![微信截图_20200408104750.png](https://pic.leetcode-cn.com/3df8aee0aa8249c93d2abda40790e0cadfe70647db5782344168b6b3519d982b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200408104750.png)

由题我们可以先封装一个求位数之和的函数，
其次我们可以假设机器人从坐标【0，0】开始运动，那么移动的方向只剩下 **↓**和**→**两个方向
利用解法深度优先遍历，解决本题
### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    let res = 0;
    // 行走的记录
    const record={};
    /**
     * 递归 把m*n方格走完 默认x，y >= 0
     * 该函数只往右和下两个方向走
     * @param {number} x 水平方向
     * @param {number} y 垂直方向
     */
    function dfs(x,y){
        x=x||0;
        y=y||0;
        if(x>=m || y>=n)
            return 
        if(!record[`${x}-${y}`] && sumDigits(x)+sumDigits(y)<=k){
            res++;
            record[`${x}-${y}`]=true; // 记录走过的路
            dfs(x+1,y); // 往右走
            dfs(x,y+1); //往下走
        }
    }
    dfs();
    return res;
};

/**
 * 计算位数之和
 * @param {number} num
 * @return {number}
 */
function sumDigits(num){
    let res=0;
    while(num){
        res += num%10;
        num = parseInt(num/10);
    }
    return res;
}
```
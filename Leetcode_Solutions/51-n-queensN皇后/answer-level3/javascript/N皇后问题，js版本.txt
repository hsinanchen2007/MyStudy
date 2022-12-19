### 解题思路
不能攻击的关键在于： 1.每一行或列不能出现2个及以上皇后;2.对角线上也不能出现重复皇后
声明一个长度为n的数组，下标代表行号，数组元素代表列号，因此保证数组内元素不重复就能满足条件1; 数组中任意两个元素的值相减，下标相减，取绝对值之后，结果不相等，满足条件2
做完筛选之后，得到所有满足条件的组合，将其格式化为题目要求的形式即可。


### 代码

```javascript
/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function (n) {
    let res = []
    let backTrack = function (arr, cur) {
        let len = arr.length
        if (len == cur) {
            res.push(arr.map(v => {
                return `${".".repeat(v)}Q${".".repeat(n - v - 1)}`
            }))
            return
        }
        for (let i = 0; i < len; i++) {
            arr[cur] = i //假设 第cur行，第i个位置可以摆放
            let flag = true
            for (let j = 0; j < cur; j++) {
                let abs = i - arr[j];
                if (arr[j] == i || (abs > 0 ? abs : -abs) == cur - j) {
                    flag = false
                    break
                }
            }
            if (flag) { //满足条件 ，保存路径，筛选下一行
                backTrack(arr.slice(), cur + 1)
            }
        }
    }
    backTrack(new Array(n), 0) //从第0行开始
    return res
};
```
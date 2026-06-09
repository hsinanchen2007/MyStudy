看到题目，很容易想到当前n的结果是依赖上一个n-1的结果。
n = 1，有1种组合
n = 2，有2种组合，在n = 1的基础上插空；
n = 3，有5种组合，在n = 2的基础上插空，5 = 3 + 2；
...

如何确定插入位置？
在一组括号"()"的左右、中间可插入，但是可能存在重复，用Set确保无重复，最后转成数组返回。

当然，开销比较大。。。
![image.png](https://pic.leetcode-cn.com/9727e7cd7a72af6749c0c953381b7c4e52931af9962ffadcb2e4b7575faa4c25-image.png)


```js
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    if (n === 0) {
        return;
    } else if (n === 1) {
        return ["()"];
    } else  {
        let prev = generateParenthesis(n-1);
        let curr = new Set();
        for (let item of prev) {
            let i = 0;
            while (i < item.length - 1) {
                if (item.slice(i, i+2) === '()') {
                    let before = item.slice(0, i);
                    let after = item.slice(i+2); 
                    curr.add(`${before}(())${after}`);
                    curr.add(`${before}()()${after}`);
                    i += 2;
                    continue
                }
                i += 1;
            }
        }
        return [...curr];
    }
};
```

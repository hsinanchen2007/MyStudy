### 解题思路
周赛 week179 的第一题
手速题
1. case 1 当 n 为 0 的时候返回空字符
2. case 2 当 n 是奇数的时候返回全是 a 的字符串
3. case 3 如果是偶数，且 n / 2是奇数就 ab 兑半
4. case 4 如果是偶数，且 n / 2 是偶数就 ab 兑半，且各自减少一个换成 c 跟 d（或者 ab 兑半后，a 的数量加一， b 的数量减一）


### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var generateTheString = function(n) {
    if(n == 0) return ''
    if (n % 2 == 1) {
        return 'a'.repeat(n)
    } else {
        if((n / 2) % 2 == 1 ) return 'a'.repeat(n/2) + 'b'.repeat(n/2)
        else return 'a'.repeat(Math.floor(n / 2) - 1) + 'b'.repeat(Math.floor(n / 2) - 1) + 'c' +'d'
    }
};
```
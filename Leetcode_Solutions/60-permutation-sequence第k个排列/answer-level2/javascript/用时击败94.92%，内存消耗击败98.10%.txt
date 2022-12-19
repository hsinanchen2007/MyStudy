![1.png](https://pic.leetcode-cn.com/0854c1151aa9c5ef613e44458dd1948d4f46672b020c2a1fe2c382ad5a870512-1.png)
### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    const fac = [0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];  //1!~9!
    let res = '';
    let arr = [];
    //arr = [1, 2, 3, ..., n]
    for (let i = 1; i < n + 1; i++) {
        arr.push(i);
    }
    //通过foo不断获取排列的下一个数字，直到能直接获取后续数字
    const foo = (n, k) => {
        if (k === fac[n]) {  //k与n!相等，返回最后一个排列
            res += arr.reverse().join('');
        } else if (k === fac[n - 1]) {  
            //k与(n - 1)!相等，下一个数字为arr[0]
            //再次调用foo(n - 1, k)的话，第一个if会成立，故可以直接加上最后一个排列
            res += arr.shift();
            res += arr.reverse().join('');
        } else {  //得到排列的下一个数字
            let num = 0;
            while (k > fac[n - 1]) {
                k -= fac[n - 1];
                num++;
            }
            res += arr[num];
            arr.splice(num, 1);  //从arr里移除该数字
            foo(n - 1, k);
        }
    }
    foo(n, k);
    return res;
};
```
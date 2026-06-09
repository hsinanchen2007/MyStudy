### 解题思路
遍历字符串,用一个map记录出现次数，result记录回文对，count记录单个字符出现次数，如果该字符未出现过,则该字符对应次数记为1，count + 1;
出现过的话分两种情况：
 1、出现过的次数为奇数,此时计数+1,可作为一个回文对,res + 2; 单个字符的计数减去1: count - 1
 2、出现过的次数为偶数(这种情况下可以当做未出现过对待);
最后如果count >= 1;则说明可以组成aba类的回文,最终结果为result + 1;否则result即为最终结果;
这里用Map和Object试了下，速度差别很大。。。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {

let map = new Map();
 let result = 0;
    let count = 0;

    for (let num of s) {
        let val = map.get(num);
        if (val == 1) {
            map.set(num, 2);
            result += 2;
            count -= 1;
        }else {
            map.set(num, 1);
            count += 1;
        }
    }


    // let map = {};
    // for(let i = 0; i < s.length; i ++) {
    //     if(map[s[i]] == 1 ){
    //         map[s[i]] = 2;
    //         result += 2;
    //         count -= 1;
    //     } else {
    //         map[s[i]] = 1;
    //         count += 1;
    //     }
    // }

    return  count >= 1 ? result + 1 : result;

};
```
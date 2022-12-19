
```
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let jarr = J.split("");
    let sarr = S.split("");
    return sarr.filter(item=>jarr.includes(item)).length
};
```
![c4f08ac775c5f01b08ad25fa1aff2021.png](https://pic.leetcode-cn.com/520ed7e90f8e83f2ced416bb22b99647ff2c11e80674db3cb77ed34ae604fa1e-c4f08ac775c5f01b08ad25fa1aff2021.png)

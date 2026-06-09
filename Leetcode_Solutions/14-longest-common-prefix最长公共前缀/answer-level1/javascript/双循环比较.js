### 解题思路
1.提取strs[0]为第一项
2.双层循环依次比较，即每次比较strs的item中的第 strs[0]的第[i]位是否相同



### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 * 
 * 执行用时 :60 ms, 在所有 JavaScript 提交中击败了94.05%的用
 * 内存消耗 :35.3 MB, 在所有 JavaScript 提交中击败了49.41%的
 */
var longestCommonPrefix = function (strs) {
    // 最长公共前缀，初始化为1;
    let theSame = ''; 
    // 如果strs的长度是0，则直接返回'‘
    if (strs.length == 0) {
        return ''
    }
    //如果strs的长度为1，则直接返回strs[0]
    if (strs.length == 1) {
        return strs[0]
    }
    // 双循环依次比较strs[0]和后面
    for (let i = 0; i < strs[0].length; i++) {
        // 为了确定所有item中当前位数(i)的字母是否相同，默认是相同的。
        let isSame = true;
        // 从strs的第1项开始比较，当前的位数(i)的字母是否相同
        for (let j = 1; j < strs.length; j++) {
            if (strs[0][i] != strs[j][i]) {
                //不相同则设置为false，并且跳出第一层循环
                isSame = false;
                break;
            }
        }
        // 不相同则跳出循环，相同则设置公共前缀
        if (!isSame) {
            break;
        } else {
            theSame = theSame + strs[0][i]
        }
    }
    return theSame
};
```
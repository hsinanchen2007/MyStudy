### 解题思路
执行用时 : 392 ms, 在所有 JavaScript 提交中击败了47.06%的用户
内存消耗 : 40.2 MB, 在所有 JavaScript 提交中击败了94.12%的用户

把字母数组循环两次，循环第二次的时候，把第一次循环的当前值拆分放到数组tempArr中，用数组tempArr中的字符一一与后面出现的字母进行比较，看是否存在当前字母，存在即停止循环tempArr，跳回words数组第二次循环中重新查找是否有字母重合。
如果在第二次循环之后没有发现有重合字符，就计算出来字符长度乘积并找出最大值。
### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function(words) {
    var maxNum = 0;     // 存放最大值
    var leftLen = 0;    // 对比字符串长度
    var rightLen = 0;   // 与对比字符串不相同字符串长度
    for(let i = 0; i< words.length; i++){
        let tempArr = [...words[i]]; // 字符串转为数组
        let isExist = -1;   // 判断是否存在相同字符的标识
        for(let m = i+1; m < words.length; m++){
            isExist = -1;
            for(var j = 0; j < tempArr.length; j++){
                isExist = words[m].indexOf(tempArr[j]);
                // 如果有相同字符，立即停止循环
                if(isExist>-1){
                    break;
                }
            }
            if(isExist<0){
                leftLen = words[i].length;
                rightLen = words[m].length;
                maxNum = Math.max(maxNum, leftLen*rightLen);  // 找出乘积最大值
            }
        }
    }
    return maxNum;
};
```
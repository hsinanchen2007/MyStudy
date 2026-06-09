```
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */

var wordBreak = function(s, wordDict) {
    if (s == '') {
        return true
    }
    let len = wordDict.length
    for (let i = 0; i < len; i++) {
        let item = wordDict[i];
        if (s.indexOf(item) == 0) {
            let temp = checkOnAndOn(s, item)
            // 对测试用例中的长段文字做的优化，即对某个字典中的字，在s中做连续性检查；下面的调用太深，用时会很长
            let flag = false
            if (s == temp) {
                flag = wordBreak(s.substring(item.length , s.length), wordDict)  
            } else {
                flag = wordBreak(temp, wordDict)  
            }
                
            if (flag) {
                return true
            }   
        }
    }
    return false

    function checkOnAndOn(s, itemStr) {
        if (s.length < itemStr) return s
        if (s.substring(0, itemStr.length) === itemStr) {
            return checkOnAndOn(s.substring(itemStr.length, s.length), itemStr)
        }
        return s
    }
};
```

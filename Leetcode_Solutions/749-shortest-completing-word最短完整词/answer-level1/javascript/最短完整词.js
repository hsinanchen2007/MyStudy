```js
var shortestCompletingWord = function(licensePlate, words) {
    // 有效牌照，只包含小写字母
    let license = licensePlate.replace(/[^a-zA-Z]/g, '').toLowerCase();
    // 存储包含有效牌照的所有单词，及其length
    let map = new Map();
    for (let i = 0; i < words.length; i++) {
        let flag = true;
        let str = words[i];
        for (let j = 0; j < license.length; j++) {
            let index = str.indexOf(license[j]);
            if (index == -1) {
                flag = false;
                break;
            } else {
                // 处理有效牌照中出现相同的字母
                str = str.slice(0, index) + str.slice(index + 1, str.length)
            }
        }
        if (flag) {
            map.set(words[i], words[i].length)
        } 
    }
    // 最小length的完整词
    let minVals = [];
    // 完整词的最小length
    let minIndex = Math.min.apply(Math, [...map.values()]);
    for (let [key, val] of map) {
        if (minIndex == val) {
            minVals.push(key)
        }
    }
    return minVals[0]
};
```

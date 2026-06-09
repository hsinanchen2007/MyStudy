
解法1：暴力遍历，逐个匹配计算个数
时间复杂度O(50000 * 5000 * 50)

```
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function(S, words) {
    let num = 0;
    words.forEach((item) => {
        let flag = true;
        let fromIndex = -1; //初始应该是0的，为了配合下次查找在上次的下标+1
        let wordAry = Array.from(item);
        wordAryLength = wordAry.length;
        for(let index = 0; index < wordAryLength; index++) {
            let findIndex = S.indexOf(wordAry[index], fromIndex + 1);//下次查找在上个字母查找位置后+1
            if (findIndex >= 0) {
                fromIndex = findIndex;//找到更新下标
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            num++;
        }
    });
    return num;
};
```
> 执行用时 :
448 ms
, 在所有 JavaScript 提交中击败了
33.33%
的用户

> 内存消耗 :
43.6 MB
, 在所有 JavaScript 提交中击败了
80.00%
的用户

解法2：和上一个相同，只是多了优化（对于已经计算过的项用Map保存，因为测试用例有些是很多的重复项，还有一个优化是记录S中字母的次数，然后看是否存在或者-1，但是好像变慢了，就没贴了）


```
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function(S, words) {
    let num = 0;
    let resultMap = new Map();
    
    words.forEach((item) => {
        if (resultMap.get(item)) {
            num++;
        } else {        
            let flag = true;
            let fromIndex = -1; //初始应该是0的，为了配合下次查找在上次的下标+1
            let wordAry = Array.from(item);
            wordAryLength = wordAry.length;
            for(let index = 0; index < wordAryLength; index++) {
                let s = wordAry[index];
                let findIndex = S.indexOf(wordAry[index], fromIndex + 1);//下次查找在上个字母查找位置后+1
                if (findIndex >= 0) {
                    fromIndex = findIndex;//找到更新下标
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                num++;
                resultMap.set(item, true);
            }
        }
    });
    return num;
};
```
> 执行用时 :
308 ms
, 在所有 JavaScript 提交中击败了
50.00%
的用户

> 内存消耗 :
45.8 MB
, 在所有 JavaScript 提交中击败了
80.00%
的用户
### 解题思路
竞赛的时候第一想法就是暴力求解，但是想了想这个时间复杂度还是放弃了，咋整嘛，太难了。
到了晚上，想着学习下别人的思路，那就打开题解瞅瞅吧，发现基本一样，所以还是写上去，竟然没有超时，也是服了。

### 基本思路
words - result = 0, 找出所有字母的权重，左正右负。同时记录每个单词的首字母，这些字母是不能为 0 的
因为 1 < words[i].length, result.length < 7, 所以最高位的系数是 1000000。
    示例 1 计算的结果
    ```
    D: 1
    E: 91
    M: -9000
    N: -90
    O: -900
    R: 10
    S: 1000
    Y: -1
    ```
    经过上面处理，可以知道一共用到了哪些字母: ["D", "N", "E", "S", "R", "O", "M", "Y"],  以及每个字母相应的系数
    以及首字母 "S" ,"M"
DFS 暴力检查，每一轮，我们需要的参数是，当前的处理字母的下标， 前面处理中用过哪些数字， 处理过的字母对应的数字的映射关系。
[0-9] 依次赋值给当前的字母， 如是是首字母（"S", "M"）则跳过, 如果当前数值已经复制给其他字母也跳过
当处理到最后一轮，也就是所有字母都有了对应数值，根据系数和赋值计算结果是否为 0
如果和为 0， 表明方程可解。中止程序
如果所有情况都遍历过任然没有结束，表明无解。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} result
 * @return {boolean}
 */
var isSolvable = function(words, result) {
    const weights = [1, 10, 100, 1000, 10000, 100000, 1000000]
    const headWord = new Set()
    const wordMap = Object.create(null)
    const deep = words.length
    words.push(result)
    for (let i = 0;i<=deep;i++) {
        const len = words[i].length
        for (let j = len - 1;j>=0;j--) {
            const word = words[i][j]
            if (wordMap[word]) {
                wordMap[word] += i < deep ? weights[len-j-1] : -weights[len-j-1]
            } else {
                wordMap[word] = i < deep ? weights[len-j-1] : -weights[len-j-1]
            }
            if(j===0) {
                headWord.add(word)
            }
        }
    }
    const allWords = Object.keys(wordMap)
    const wordsCount = allWords.length
    const forceLoop = (index, numbers, wordToNumber) => {
        if (index === wordsCount) {
            const sum = allWords.reduce((pre, cur) => {
                const weight = wordMap[cur]
                pre += weight * wordToNumber[cur]
                return pre
            }, 0)
            return sum === 0
        }
        const word = allWords[index]
        for (let i = 0;i<10;i++) {
            if (i === 0 && headWord.has(word) || numbers[i]) continue
            numbers[i] = 1
            wordToNumber[word] = i
            if (forceLoop(index+1, numbers, wordToNumber)) return true
            numbers[i] = 0
        }
        return false
    }
    return forceLoop(0, new Array(10).fill(0), Object.create(null))
};
```

### END
没什么特别的亮点，只是做下记录。
第一次写题解，溜了溜了。。。
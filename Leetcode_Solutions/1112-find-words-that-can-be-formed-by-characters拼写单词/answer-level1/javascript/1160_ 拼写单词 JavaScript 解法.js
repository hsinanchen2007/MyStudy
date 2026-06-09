
执行用时 : 144 ms, 在所有 javascript 提交中击败了86.53%的用户
内存消耗 :40.6 MB, 在所有 javascript 提交中击败了100.00%的用户

基本思路是两个遍历，遍历words中的每个单词里的字母是否都在chars里，注意每次拼写时，chars中的每个字母只能使用一次，因此若匹配到需用splice方法将该字母去掉再进行遍历；若未匹配到字母，则直接退出循环

复杂度O(n^2)，这个复杂度真的一般般，不知道为啥打败100%的用户了emmm
```
var countCharacters = function(words, chars) {
    let len = 0
    for(let word of words) {
        const wordLen = word.length
        let charArr = chars.split('')
        for(let i = 0; i < wordLen; i++) {
            const char = word[i]
            const wordIndex = charArr.indexOf(char)
            if (wordIndex === -1) {
                break
            } else {
                charArr.splice(wordIndex, 1)
                if (i === wordLen - 1) {
                    len += wordLen
                }
            }
        }
    }
    return len
};
```


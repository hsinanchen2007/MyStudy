```
var ladderLength = function(beginWord, endWord, wordList) {
    if(!wordList.includes(endWord)) return 0;
    let queue = [beginWord];
    let i = queue.length;
    let level = 0;
    while (i) {
        level++;
        while(i--) {
            const front = queue.shift();
            if(!front) continue;
            if(front === endWord) return level;
            for(let j = 0; j < wordList.length; j++) {
                if(isOnlyOneDiff(front, wordList[j])) {
                    queue.push(wordList[j]);
                    wordList.splice(j, 1);
                    j--;
                }
            }
        }
        i = queue.length;
    }
    return 0;

    function isOnlyOneDiff(str1, str2) {
        if(str1 === str2) return false;
        let i = str1.length;
        let diff = 0;
        while(i--) {
            if(str1[i] !== str2[i]) diff++;
            if(diff > 1) return false;
        }
        return true;
    }
};
```

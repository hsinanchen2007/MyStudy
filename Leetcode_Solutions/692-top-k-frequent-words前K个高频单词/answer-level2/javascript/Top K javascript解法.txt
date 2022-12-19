```
//time complexity: O(NlogN)
//space complexity: O(N)
var topKFrequent = function(words, k) {
    let res = [];

// mapping the words 
    let mapWords = new Map([]);
    for (let i = 0; i < words.length; i++) {
        if (mapWords.has(words[i])) {
            let num = mapWords.get(words[i]) + 1;
            mapWords.set(words[i], num);
        } else {
            mapWords.set(words[i], 1);
        }
    }
// sort words
    let sortedWords = [...mapWords].sort((prev, next) => next[1] - prev[1] || prev[0].localeCompare(next[0]));

// get the right number of words
    for (let i = 0; i < k; i++) {
        res.push(sortedWords[i][0]);        
    }

    return res;
};
```

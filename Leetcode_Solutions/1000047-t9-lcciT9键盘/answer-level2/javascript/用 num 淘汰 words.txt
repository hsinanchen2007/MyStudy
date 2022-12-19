```
/**
 * @param {string} num
 * @param {string[]} words
 * @return {string[]}
 */
var getValidT9Words = function(num, words) {
    let nums =num.match(/./g);
    let map={
        2:['a','b','c'],
        3:['d','e','f'],
        4:['g','h','i'],
        5:['j','k','l'],
        6:['m','n','o'],
        7:['p','q','r','s'],
        8:['t','u','v'],
        9:['w','x','y','z']
    }
    for(let i in nums){
        for(let j in words)
        if(map[nums[i]].indexOf(words[j].charAt(i))==-1){
            words.splice(j,1)
        }
    }
    return words;
};
```

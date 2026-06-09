bfs,没什么好说的
```
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    const len = digits.length;
    if(!len) return [];
    const record = {
        2: ['a', 'b', 'c'],
        3: ['d', 'e', 'f'],
        4: ['g', 'h', 'i'],
        5: ['j', 'k', 'l'],
        6: ['m', 'n', 'o'],
        7: ['p', 'q', 'r', 's'],
        8: ['t', 'u', 'v'],
        9: ['w', 'x', 'y', 'z']
    }
    const queue = record[digits[0]].slice(0);
    let i;
    let level = 1;
    while(level < len) {
        i = queue.length;
        while(i--) {
            const front = queue.shift();
            const selects = record[digits[level]];
            selects.forEach(select => queue.push(front + select));
        }
        level++;
    }
    return queue;
};
```

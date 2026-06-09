### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    const store = {}
    for(let i = 0; i < magazine.length; i ++) {
        if(!store[[magazine[i]]]) {
            store[magazine[i]] = 1
        }else {
            store[magazine[i]] ++
        }
    }
    for(let i = 0; i < ransomNote.length; i ++) {
        if(store[ransomNote[i]]){
            store[ransomNote[i]] --
        }else{
            return false
        }
    }
    return true
};
```

欢迎 star: https://github.com/OhIAmFine/LeetCode-my-answer-of-javascript
显然，对于一个单词 word，只要其中的每个字母的数量都不大于 chars 中对应的字母的数量，那么就可以用 chars 中的字母拼写出 word。所以我们只需要用一个哈希表存储 chars 中每个字母的数量，再用一个哈希表存储 word 中每个字母的数量，最后将这两个哈希表的键值对逐一进行比较即可。


```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let map = new Map();
    for(let c of chars){
        if (map.has(c)) {
            map.set(c, map.get(c)+1);
        } else {
            map.set(c,1); 
        }
    }
    
    let res=0;
    for (let w of words) {
      if (check(w, map)) {
        res += w.length;
      }
    }

    return res;
};

function check(word, map){
    var newMap = new Map(map);
    let flag = true;
    for (let w of word){
        if (newMap.has(w) && newMap.get(w) > 0) {
            newMap.set(w, newMap.get(w) - 1);
        }
        else {
            flag = false;
            break;
        }
    }
    return flag;
}
```
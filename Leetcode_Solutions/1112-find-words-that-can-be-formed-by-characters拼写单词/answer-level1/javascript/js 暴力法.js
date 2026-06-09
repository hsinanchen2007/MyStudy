### 解题思路

 * 把chars转换成map 字母，出现次数
 * 如果words的单词，出现的字母都在map中，并且数量不超过num，那么这个字母是true
 * 返回长度增加word的length

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    const known = parseWordToMap(chars);
    let total = 0;
    for(let word of words) {
        const map1 = parseWordToMap(word);
        if(test(map1, known)) {
            console.log(map1, known);
            total += word.length;
        }
    }

    return total;
};

function parseWordToMap(str) {
    let map = new Map();
    for(let s of str) {
        if(map.has(s)) {
            map.set(s,map.get(s) + 1);
        } else {
            map.set(s, 1);
        }
    }
    return map;
}

/**
 * map1 included in map2
 * @param {*} map1 
 * @param {*} map2 
 */
function test(map1, map2) {
    for(let k of map1.keys()){
        if(!map2.has(k) || map2.get(k) < map1.get(k)) {
            return false;
        }
    }
    return true;
}


```
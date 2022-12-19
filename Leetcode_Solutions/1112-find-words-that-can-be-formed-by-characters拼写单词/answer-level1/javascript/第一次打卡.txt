### 解题思路
刚开始想到用全排列搞，但是一看排列算法想想还是算了。根据要求想到只要words中的单词在chars中有并且words中的数量小于等于chars中的数量就算掌握了。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
function createMap(str) {
        let charMap = new Map();
        for (let i=0;i<str.length;i++) {
            if (charMap.has(str.charAt(i))) {
                let num = charMap.get(str.charAt(i));
                charMap.set(str.charAt(i), ++num);
            } else {
                charMap.set(str.charAt(i), 1);
            }
        }
        return charMap;
    }
    let ans = 0;
    for (let i=0;i<words.length;i++) {
        if (words[i].length > chars.length) {
            continue;
        } else {
            let w = words[i];
            let map = createMap(chars);
            let m2 = createMap(w);
            let cnt = 0;
            for (let j=0;j<w.length;j++) {
                if (map.has(w.charAt(j)) && map.get(w.charAt(j)) >= m2.get(w.charAt(j))) {
                    cnt++;
                }
            }
            if (cnt===w.length) {
                ans += w.length;
            }
        }
    }
    return ans;
};
```
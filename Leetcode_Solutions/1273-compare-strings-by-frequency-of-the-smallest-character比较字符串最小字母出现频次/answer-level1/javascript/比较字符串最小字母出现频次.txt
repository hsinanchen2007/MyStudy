### 解题思路

1. 将 `queries` `words` 改为最小字母出现频次的数组；
2. 找出 `words` 中比 `queries` 中每一项大的次数

### 代码

```javascript
/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    const getSmaller = function(arr){
        const { length } = arr;
        for(let i = 0; i < length; i++){
            arr[i] = [...arr[i]].sort();
            arr[i] = arr[i].lastIndexOf(arr[i][0]) + 1;
        }
        return arr;
    }
    let result = [];
    queries = getSmaller(queries);
    words = getSmaller(words);
    for(let i = 0; i < queries.length; i++){
        let count = 0;
        for(let j = 0; j < words.length; j++){
            if(words[j] > queries[i]){
                count++;
            }
        }
        result.push(count);
    }
    return result;
};
```
![image.png](https://pic.leetcode-cn.com/947600bc938829b5ec06dddaa126a2ca44aac6b9d24227b5b7af1507874ca10f-image.png)

1. 方法一
```
/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    let getFrequency = (str) => {
        let arr = str.split('').sort().join('')
        let smallestStr = arr[0]
        let num = 1
        for(let i = 1; i < arr.length; i++) {
            if (arr[i] === smallestStr) {
                num++
            } else {
                break
            }
        }
        return num
    }
    let list = new Array(12).fill(0)
    let result = []
    for(let i of words) {
        list[getFrequency(i)]++
    }
    for(let i = 10; i >= 0; i--) {
        list[i] += list[i+1]
    }
    for(let i of queries) {
        result.push(list[getFrequency(i) + 1])
    }
    return result
};
```

2. 方法二
```
/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    let getFrequency = (str) => {
        let arr = str.split('').sort().join('')
        let smallestStr = arr[0]
        let num = 1
        for(let i = 1; i < arr.length; i++) {
            if (arr[i] === smallestStr) {
                num++
            } else {
                break
            }
        }
        return num
    }
    let arrFrequency = (arr) => {
        let list = []
        for(let i of arr) {
            list.push(getFrequency(i))
        }
        return list
    }
    let queriesArr = arrFrequency(queries)
    let wordsArr = arrFrequency(words)
    let list = []
    for(let i of queriesArr) {
        let num = 0
        for(let j of wordsArr) {
            if (i < j) num++
        }
        list.push(num)
    }
    return list
};
```


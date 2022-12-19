### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function (s) {
    // 笨办法 类似匹配括号
    // let map = {
    //     'R': 'L',
    //     'L': 'R'
    // }

    // let store = []

    // let arr = s.split('')

    // let count = 0
    // for (let i = 0; i < arr.length; i++) {

    //     console.log(arr[i], store.length && arr[i] === store[store.length - 1])
    //     if (store.length && arr[i] === store[store.length - 1]) {
    //         store.pop()

    //         console.log(store)
    //     } else {
    //         store.push(map[arr[i]])
    //         console.log(store)
    //     }

    //     // 清空store计数+1
    //     if (store.length === 0) {
    //         count++
    //     }

    // }

    // return count


    // 方法二 找L R
    let Rcount = 0
    let Lcount = 0
    let total = 0

    let arr = s.split('')

    for(let item of arr){
        if(item === 'R'){
            Rcount++
        } else if(item === 'L'){
            Lcount++
        }

        if(Rcount === Lcount){
            total++
            Rcount = 0
            Lcount = 0
        }
    }

    return total


};
```
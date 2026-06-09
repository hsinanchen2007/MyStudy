### 解题思路
根据判断index与numRows不相等，递归call函数，往arr里push

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function (numRows) {
    let index = 0
    let arr = []
    function call(index) {
        let filterArr = arr[arr.length - 1]
        if (index === numRows) {
        } else {
            if (index === 0 || index === 1) {
                index === 0 ? arr.push([1]) : arr.push([1, 1])
            } else {
                let a = []
                for(let i =0 ;i <filterArr.length - 1; i++){
                    a.push(filterArr[i] + filterArr[i+ 1])
                }
                a.push(1)
                a.unshift(1)
                arr.push(a)
            }
            index++
            call(index)
        }

    }
    call(index)
    return arr
};
```
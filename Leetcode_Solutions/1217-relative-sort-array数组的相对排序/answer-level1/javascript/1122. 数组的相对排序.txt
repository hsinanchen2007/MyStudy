关于解这道题的思路：

- ``arr1`` 数组中跟 ``arr2`` 中存在交集的部分，按照在 ``arr2`` 数组中的顺序先排序
- 排序完后，``arr1`` 数组中剩余的部分按升序合并到之前的数组里

第一版程序：

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let result = []

    while (arr2.length) {
        let i = arr1.length
        let target = arr2.pop()
        while (i--) {
            if (arr1[i] === target) {
                result.unshift(target)
                arr1.splice(i, 1)
            }
        }
    }
    return result.concat(arr1.sort((a, b) => a - b))
};
```

稍加思考后，觉得内层的 ``while`` 循环其实不必要。  
第二版程序：
```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let result = [], i = 0, target
    while (true) {
        if (i === 0) {
            i = arr1.length
            target = arr2.pop()
        }
        if (arr1[--i] === target) {
            result.unshift(target)
            arr1.splice(i, 1)
        }
        if (!arr2.length && !i) {
            break
        }
    }
    return result.concat(arr1.sort((a, b) => a - b))
};

```
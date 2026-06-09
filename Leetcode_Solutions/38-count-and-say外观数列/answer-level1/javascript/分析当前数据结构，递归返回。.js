# 可以将将要下次报数的结果格式化

比如

1211 -> [
    { count: 1, value: 1 },
    { count: 1, value: 2 },
    { count: 2, value: 1 },
]

111221 -> [
    { count: 3, value: 1 },
    { count: 2, value: 2 },
    { count: 1, value: 1 },
]

将数据按照顺序就可以拼出下一个的结果，递归返回。

``` javascript
if (n === 1) {
        return "1"
    }

    const countSameValueAndLength = (arr) => {
        let res = []
        let count = 1
        let i = 0
        for (let j = 1; j < arr.length + 1; j++) {
            if (arr[j] === arr[i]) {
                count++
            } else {
                res.push({ count, value: arr[i] })
                count = 1
            }
            i++
        }
        return res
    }

    const lastArr = countAndSay(n - 1)
    const structure = countSameValueAndLength(lastArr)

    return structure.reduce((sum, current) => sum + current.count.toString() + current.value.toString(), "")
```


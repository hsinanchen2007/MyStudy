```
const myWay = num => {
    do {
        num = num.toString().split('').reduce((a, b) => parseInt(a) + parseInt(b))
    } while (num > 10)
    return num
}

```
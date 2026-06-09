判断套判断，循环接循环
这！就是朋克！

```
/**
 * @param {string} time
 * @return {string}
 */
var nextClosestTime = function (time) {
    let numArr = [time[0], time[1], time[3], time[4]]
    let stringArr = [time[0], time[1], time[2], time[3], time[4]]
    let num = 4

    numArr.sort((a, b) => a - b)

    for (let i = 0; i < 4; i++) {
        if (numArr[i] > time[4] && numArr[i] <= '9') {
            stringArr[4] = numArr[i]
            return stringArr.join('')
        }
    }
    for (let i = 0; i < 4; i++) {
        if (numArr[i] > time[3] && numArr[i] <= '5') {
            stringArr[3] = numArr[i]
            num = 1

            break
        }
    }
    if (num === 4) {
        for (let i = 0; i < 4; i++) {
            if (time[0] === '2') {
                if (numArr[i] > time[1] && numArr[i] <= '3') {
                    stringArr[1] = numArr[i]
                    num = 2

                    break
                }
            } else {
                if (numArr[i] > time[1] && numArr[i] <= '9') {
                    stringArr[1] = numArr[i]
                    num = 2

                    break
                }
            }
        }
    }
    if (num === 4) {
        for (let i = 0; i < 4; i++) {
            if (numArr[i] > time[0] && numArr[i] <= '2') {
                stringArr[0] = numArr[i]
                num = 3

                break
            }
        }
    }

    if (num >= 4) {
        for (let i = 0; i < 4; i++) {
            if (numArr[i] < time[0]) {
                stringArr[0] = numArr[i]

                break
            }
        }
    }
    if (num >= 3) {
        for (let i = 0; i < 4; i++) {
            if (numArr[i] < time[1]) {
                stringArr[1] = numArr[i]

                break
            }
        }

    }
    if (num >= 2) {
        for (let i = 0; i < 4; i++) {
            if (numArr[i] < time[3]) {
                stringArr[3] = numArr[i]

                break
            }
        }
    }
    if (num >= 1) {
        for (let i = 0; i < 4; i++) {
            if (numArr[i] < time[4]) {
                stringArr[4] = numArr[i]

                break
            }
        }
    }

    return stringArr.join('')
}
```

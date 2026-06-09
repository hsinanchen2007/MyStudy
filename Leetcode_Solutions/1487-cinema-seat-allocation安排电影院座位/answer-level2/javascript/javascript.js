### 解题思路
反正我是改吐了....

### 代码

```javascript
/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    let arr = []
    reservedSeats.forEach(ele => {
        if(ele[1] !== 1 && ele[1] !== 10) {
            !arr[ele[0]] && (arr[ele[0]] = [])
            arr[ele[0]].push(ele[1])
        }
    })
    arr = arr.filter(ele => ele)
    let ans = (n - arr.length) * 2
    arr.forEach(ele => {
        let cur = Array(4).fill(1)
        for (let i in ele) {
            if(ele[i] == 2 || ele[i] == 3) {
                cur[0] = 0
            } else if(ele[i] == 4 || ele[i] == 5) {
                cur[1] = 0
            } else if(ele[i] == 6 || ele[i] == 7) {
                cur[2] = 0
            } else if(ele[i] == 9 || ele[i] == 8) {
                cur[3] = 0
            }
        }
        let curStr = cur.join('')
        let oneArr = ['0110'  ,'1110'  ,'0111'  ,'1100'  ,'0011'  ,'1101'  ,'1011']
        if(oneArr.indexOf(curStr) >= 0) {
            ans += 1
        }
    })
    return ans 
};
```
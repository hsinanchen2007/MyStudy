```
/**
 * @param {number} num
 * @return {string}
 */
const mapping = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I",
}
const order = Object.keys(mapping).map(i => parseInt(i)).sort((a, b) => b-a)

var intToRoman = function(num) {
    let res = ""
    while(num>0) {
        for (let index = 0; index<order.length; index++) {
            const curr = order[index]
            if (num>=curr) {
                res += mapping[curr]
                num -= curr
                break
            }
        }
    }
    return res
};
```

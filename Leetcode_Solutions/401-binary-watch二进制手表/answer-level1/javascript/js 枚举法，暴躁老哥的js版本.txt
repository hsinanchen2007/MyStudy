### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {string[]}
 */
var readBinaryWatch = function (num) {
    const res = []
    const hourstrs = [["0"], ["1", "2", "4", "8"], ["3", "5", "6", "9", "10"], ["7", "11"]]
    const minstrs = [
        ["00"],
        ["01", "02", "04", "08", "16", "32"],
        ["03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"],
        ["07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49","50", "52", "56"],
        ["15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"],
        ["31", "47", "55", "59"]
    ]
    for (let i = 0; i <= Math.min(3, num); i++) {
        if (num - i > 5) continue;
        const hstr = hourstrs[i];
        const mstr = minstrs[num - i];
        for (let j = 0; j < hstr.length; j++) {
            for (let k = 0; k < mstr.length; k++) {
                res.push(hstr[j] + ":" + mstr[k]);
            }
        }
    }
    return res
}
```
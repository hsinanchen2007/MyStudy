```
var numberToWords = function (num) {
    // 2147483648
    if (num == 0) return "Zero"
    const n = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"],
        d = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"],
        t = ["Hundred", "Thousand", "Million", "Billion"];
    let index = 0,
        res = []
    while (num >= 1) {
        let temp = 0,
            a = parseInt(num % 1000),
            b = a % 100
        if (a > 0) {
            if (index != 0) res.push(t[index])
            if (b != 0) res.push((b <= 20 ? n[b] : d[parseInt(b / 10)] + " " + n[b % 10]).trim())
            if (a >= 100) res.push(n[parseInt(a / 100)] + " " + t[0])
        }
        num = parseInt(num / 1000)
        index++
    }
    return res.reverse().join(" ")
};
```

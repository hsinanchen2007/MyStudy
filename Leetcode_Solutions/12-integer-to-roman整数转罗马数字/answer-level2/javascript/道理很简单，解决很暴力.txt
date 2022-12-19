一个数字的组成 就是  个 十 百 千。。。加起来组成的
罗马数字也是同理
比如3999 = 3000 + 900 + 90 + 9 = "MMM" + "CM" + "XC" + "IX"
 230 = 200 + 30 + 0 = "CC" + "XXX" + ""
那我先建立一个映射关系把 [0 1..9] [10 20..90] [100 200..900] [1000 2000 3000]的所有映射关系包含其中
map = {0: "", 1: "I", 2: "II", 3: "III", 4: "IV", 5: "V", 6: "VI", 7: "VII", 8: "VIII", 9: "IX", 10: "X", 20: "XX", 30: "XXX", 40: "XL", 50: "L", 60: "LX", 70: "LXX", 80: "LXXX", 90: "XC", 100: "C", 200: "CC", 300: "CCC", 400: "CD", 500: "D", 600: "DC", 700: "DCC", 800: "DCCC", 900: "CM", 1000: "M", 2000: "MM", 3000: "MMM" };
然后拆分题目给出的数字，从映射中取出对应的字母相加即可
完整代码如下
`/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
    let map = {0: "", 1: "I", 2: "II", 3: "III", 4: "IV", 5: "V", 6: "VI", 7: "VII", 8: "VIII", 9: "IX", 10: "X", 20: "XX", 30: "XXX", 40: "XL", 50: "L", 60: "LX", 70: "LXX", 80: "LXXX", 90: "XC", 100: "C", 200: "CC", 300: "CCC", 400: "CD", 500: "D", 600: "DC", 700: "DCC", 800: "DCCC", 900: "CM", 1000: "M", 2000: "MM", 3000: "MMM" };
    let s = num.toString();
    let res = [];
    for(let i = 0, len = s.length; i < len; i++){
        res.push(s[i] * Math.pow(10,len - i -1));
    }
    return res.reduce(function(total,currentValue){
        return total + map[currentValue]
    },map[0])
};`



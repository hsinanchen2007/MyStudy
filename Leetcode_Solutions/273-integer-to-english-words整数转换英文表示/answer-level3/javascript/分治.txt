```
/**
 * @param {number} num
 * @return {string}
 */
/*
    2 ^ 31 - 1 = 2 147 483 647, 十位数， 读做one billion one hundred forty seven million four hundred eighty three thousand six hundred forty seven
英文数量单位:
    thousand = 1000
    million = 1 000 000
    billion = 1 000 000 000
    所以规律是， 把数字每三个分为一组， 第一组没单位， 第二组单位是thousand， 第三组单位是million， 第四组单位是billion， 最多只有四组， 最少有一组
 */
const limit1 = 1000
const limit2 = 1000000
const limit3 = 1000000000
var numberToWords = function(num) {
    if(num === 0) return 'Zero'
    let f1 = Math.floor(num / limit3)
    let f2 = Math.floor((num - f1 * limit3) / limit2)
    let f3 = Math.floor((num - f1 * limit3 - f2 * limit2) / limit1)
    let f4 = num - f1 * limit3 - f2 * limit2 - f3 * limit1
    let res = ''
    if(f1) res += (' ' + three(f1) + ' Billion')
    if(f2) res += (' ' + three(f2) + ' Million')
    if(f3) res += (' ' + three(f3) + ' Thousand')
    if(f4) res += (' ' + three(f4))
    return res.trim()
};

function one(num) {
    switch(num) {
        case 0: return 'Zero'
        case 1: return 'One'
        case 2: return 'Two'
        case 3: return 'Three'
        case 4: return 'Four'
        case 5: return 'Five'
        case 6: return 'Six'
        case 7: return 'Seven'
        case 8: return 'Eight'
        case 9: return 'Nine'
    }
}

function twoEndWithZero(num) {
    switch(num) {
        case 1: return 'Ten'
        case 2: return 'Twenty'
        case 3: return 'Thirty'
        case 4: return 'Forty'
        case 5: return 'Fifty'
        case 6: return 'Sixty'
        case 7: return 'Seventy'
        case 8: return 'Eighty'
        case 9: return 'Ninety'
    }
}

function twoLessThanTwenty(num) {
    switch(num) {
        case 11: return 'Eleven'
        case 12: return 'Twelve'
        case 13: return 'Thirteen'
        case 14: return 'Fourteen'
        case 15: return 'Fifteen'
        case 16: return 'Sixteen'
        case 17: return 'Seventeen'
        case 18: return 'Eighteen'
        case 19: return 'Nineteen'
    }
}

function two(num) {
    let first = Math.floor(num / 10)
    let second = num - first * 10
    if((first === 1) && second) {
        return twoLessThanTwenty(num)
    } else if(first && !second){
        return twoEndWithZero(first)
    } else if(first) {
        return twoEndWithZero(first) + ' ' + one(second)
    } return one(second)
}

function three(num) {
    let f1 = Math.floor(num / 100)
    let f2 = num - f1 * 100
    if(f1 && f2) {
        return one(f1) + ' Hundred ' + two(f2)
    }else if(f1 && !f2){
        return one(f1) + ' Hundred'
    } else return two(f2)
}
```

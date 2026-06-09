先记录了特殊字母出现的字符，
let obj = {
      I: 1,
      IV: 4,
      V: 5,
      IX: 9,
      X: 10,
      XL: 40,
      L: 50,
      XC: 90,
      C: 100,
      CD: 400,
      D: 500,
      CM: 900,
      M: 1000,
    }
let res = 0
    for (var i = 0; i < s.length; i++) {
      if (obj[s[i] + s[i + 1]]) {
        res += obj[s[i] + s[i + 1]]
        i++
      } else {
        res += obj[s[i]]
      }
    }
然后循环对比，首页循环两位数的，两位数匹配上就把i++,跳过两位，没匹配进入下面计算一位数出现的
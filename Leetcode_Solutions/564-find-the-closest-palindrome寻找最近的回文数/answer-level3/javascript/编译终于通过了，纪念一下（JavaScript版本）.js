### 解题思路
失败了N多次之后终于通过了，害...
![微信截图_20200325152619.png](https://pic.leetcode-cn.com/6798bad22499e4739968eaa0c78e70ee99950830d5d06a244b79ff7bcb19036a-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200325152619.png)

思路很简单，但细节太多了，多了，了，，， 本来以为遍历就完事了，但要么超时，要么某极端情况不符合预期，折腾来折腾去，加了一堆判断。变成了下面的一坨。

首先分析一下，绝大多数情况下回文数长度 和 n的长度相等，某些情况下会 少一位（n = 100），或多一位(n = 999) 总之就是，

1. 新建一个数组(palindromicList)，用于存放小于n的最近回文数和大于n的最近回文数,

2. 判断n的大小，，如果长度为1，直接 减1 返回，，，额，n="11"是特殊情况，就单拎出来了

3. 将字符串n 拆开，将 0 ~ n/2长度的字符串转成数字（halfN），，，这里需要注意判断n.length的奇偶性，如果是偶数 直接截取到n/2, 如果是奇数，需要截取到 n/2 + 1 
 
4. 同时遍历小于halfN的数字(L)和大于halfN的数字(R)，并翻转，之后再和L或R拼接起来，变成回文数，，，这里又需要注意好多细节，比如某情况下L的长度会小于halfN的长度（100-->99,此时长度3变成了2），导致拼接完之后短1位(-->9999)，此时长度比 n 少了2位，，明显不科学，因此需要补回来(-->99999)，还有R的长度会大于halfN的长度（99-->100），导致拼接完之后多1位，此时需要将 翻转后的R("001") 去掉第一个元素再做拼接，，，与此同时还得根据n.length的奇偶性做判断等等，就不详细赘述了（T_T）

5. 将处理好的回文数L,R 和n进行对比， 小于n的 放在palindromicList[0], 大于n的放在palindromicList[1]中，之后中断循环

5. 最终，从palindromicList 中取出距离n最近的回文数 nearest

好累好累，，

最后最后欢迎各位同学来吐槽，，并提出宝贵建议，小弟不吝赐教~
### 代码

```javascript
/**
 * @param {string} n
 * @return {string}
 */
var nearestPalindromic = function (n) {
    let palindromicList = ["",""] //初始化数组，用于存放 小于n的最近回文数 和 大于n的最近回文数
    let nearest = "" //最近回文数
    let lenN = n.length
    let halfN = ""
    let typeN = false //不是回文数
    if (Number(n) < 11) { //个位数需要单独处理
        nearest = String(Number(n) - 1)
        return nearest
    } else if (Number(n) == 11) {
        nearest = "9"
        return nearest
    }
    if (n.split("").reverse().join("") == n) {
        typeN = true //n本身就是回文数
    }
    let isEvenNum = lenN % 2 == 0 //n是否为偶数
    if (isEvenNum) { //长度为偶数位，则截取 [0,lenN/2) 的元素
        halfN = n.slice(0, lenN / 2)
    } else { //长度为奇数位，则截取 [0,Math.ceil(lenN/2))的元素 
        halfN = n.slice(0, Math.ceil(lenN / 2))
    }
    let lenHalfN = halfN.length
    for (let L = Number(halfN) - 1, R = Number(halfN); L >= -1; L--, R++) { //halfN作为起始点 ，左右两边同时查找
        let revsL = ""
        let strL = Math.abs(L).toString()
        let lenStrL = strL.length
        if (isEvenNum) { 
            revsL = strL.split("").reverse().join("")
        } else {
            revsL = strL.substring(0, lenStrL - 1).split("").reverse().join("")
        }
        let palindromicL = strL + revsL.toString()
        if (palindromicL.length < lenN) { //处理1000 ---> 999 等 字符串长度减少的情况，需要补1位
            palindromicL += strL[0] //999 --> 9999
        }
        if (palindromicL != n) { 
            if ((Math.abs(palindromicL - n)) < (Math.abs(palindromicList[0] - n))) {
                palindromicList[0] = palindromicL
            }
        }
        let revsR = ""
        let strR = R.toString()
        let lenStrR = strR.length
        if (isEvenNum) {
            revsR = strR.split("").reverse().join("")  
            if (lenStrR > lenHalfN) {  
                revsR = revsR.substr(1)
            }
        } else {
            revsR = strR.substring(0, lenStrR - 1).split("").reverse().join("")
            if (revsR.length == 0) { //处理 个位数情况
                revsR = strR
            } else if (lenStrR > lenHalfN) { //处理 999 + 1 = 1000 等 字符串长度增加的情况，需要去掉1位
                revsR = revsR.substr(1) // 0001 --> 001 
            }
        }
        let palindromicR = strR + String(revsR) 
        if ((Math.abs(palindromicR - n) < Math.abs(n - palindromicList[0]) && (palindromicR < n))) {
            palindromicList[0] = palindromicR
            continue
        }
        if (palindromicR != n) {
            palindromicList[1] = palindromicR
            break
        }
    }
    if (palindromicList[1] - n < n - palindromicList[0]) {
        nearest = palindromicList[1]
    } else {
        nearest = palindromicList[0]
    }
    return nearest
};
```
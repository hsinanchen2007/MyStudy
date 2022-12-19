![QQ截图20200312142134.png](https://pic.leetcode-cn.com/024568db308de60dbfad1a826acae9fb7a4ca626ad173b2dd18ac78464030cf9-QQ%E6%88%AA%E5%9B%BE20200312142134.png)

首先明确一点，a和b两个字符串如果存在公因子，那么较短的那个必然包含于较长的字符串中。

那么就有三种情况了。
一、 a与b长度相等
  如果存在公因子，只能是两个字符串相等。
二、 a比b短
  将b字符串，以a为target截取，
    如果截取的数组元素超过1个，必然没有公因子。
    如果元素等于0个，意味着b字符串是a字符串重复n遍得到的，那么最大公因子就是a串
    如果元素等于1个，这里又有两种情况，
      第一种 截取后的元素与之前的不同，那么问题就又回到了最初的原点，只不过现在的ab串变成了原来的a串（较短的那个）和现在b串截取后的那个元素；
      第二种 截取后的元素与之前的相同，这就意味着较短的那个根本不在较长的字符串里面，直接返回空串即可
三、 a比b长
  情况跟第二种一样，a与b调换而已

```javascript []
var gcdOfStrings = function(str1, str2) {
  let n1 = str1.length, n2 = str2.length
  if(n1 === n2) {
    if(str1 === str2) return str1
    else return ''
  }
  if(n1 < n2) {
    let tmp = str2.split(str1).filter((val) => val !== '')
    if(tmp.length === 0) return str1
    else if(tmp.length > 1 || tmp[0] === str2) return ''
    else return gcdOfStrings(tmp[0], str1)
  }

  if(n1 > n2) {
    let tmp = str1.split(str2).filter((val) => val !== '')
    if(tmp.length === 0) return str2
    else if(tmp.length > 1 || tmp[0] === str1) return ''
    else return gcdOfStrings(tmp[0], str2)
  }
};
```
